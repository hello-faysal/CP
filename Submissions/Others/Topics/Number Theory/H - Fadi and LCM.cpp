#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 1e6 + 9;
int spf[N];
map<int, int> prime_factors;

void spf_sieve() {
  for(int i = 2; i < N; i++) {
    spf[i] = i;
  }
  for(int i = 2; i < N; i++) {
    if(spf[i] == i) {
      for(int j = i; j < N; j += i) {
        spf[j] = min(spf[j], i);
      }
    }
  }
}

bool ok(int x) {
  map<int, int> mp;
  while(x > 1) {
    mp[spf[x]]++;
    x /= spf[x];
  }
  bool ans = true;
  for(auto i: mp) {
    if(prime_factors.find(i.first) != prime_factors.end() && i.second == prime_factors[i.first]) {
      continue;
    }
    ans = false;
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  spf_sieve();

  ll n; cin >> n;
  ll x = n;
  int lim = sqrt(x + 1);
  for(int i = 2; i <= lim; i++) {
    while(x % i == 0) {
      prime_factors[i]++;
      x /= i;
    }
  }
  if(x > 1) prime_factors[x]++;

  int mn = 1;
  for(int i = 2; i <= lim; i++) {
    if(n % i == 0) {
      if(ok(i)) {
        mn = i;
      }
    }
  }

  cout << mn << ' ' << n / mn << '\n';

  return 0;
}