#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  ll n;
  while(cin >> n && n != 0) {
    if(n == 3) {
      cout << 4 << '\n';
      continue;
    }
    vector<int> v;
    int x = n - 3;
    for(int i = 1; 1LL * i * i <= x; i++) {
      if(x % i == 0) {
        if(n % i == 3) {
          v.push_back(i);
        }
        else if(n % (x / i) == 3) {
          v.push_back(x / i);
        }
      }
    }
    if(v.size() == 0) {
      cout << "No such base\n";
    }
    else {
      sort(v.begin(), v.end());
      cout << v[0] << '\n';
    }
  }

  return 0;
}