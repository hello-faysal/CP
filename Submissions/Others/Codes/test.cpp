#include <bits/stdc++.h>
using namespace std;

// @author: faysalahammedchowdhury

#define int unsigned long long  

const int mod = 1e9 + 7;

int power(int b, int p, int m) {
  if(p == 0) return 1 % m;
  if(p & 1) {
    int val = power(b, p / 2, m);
    return ((1LL * val * val) % m) * b % m;
  }
  else {
    int val = power(b, p / 2, m);
    return (1LL * val * val) % m;
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int m; cin >> m;
  map<int, int> mp;
  int mul = 1;
  bool is = true;
  for(int i = 0; i < m; i++) {
    int x; cin >> x;
    mp[x]++;
    mul = mul * x % mod;
  }

  for(auto i: mp) {
    mul = power(mul, i.second + 1, mod);
  }

  mul = sqrt(mul);
  cout << mul << '\n';

  return 0;
}