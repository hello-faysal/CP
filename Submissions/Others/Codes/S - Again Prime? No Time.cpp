#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t, cs = 0; cin >> t;
  while(t--) {
    int m, n; cin >> m >> n;
    int x = m;
    map<int, int> mp, mp2;
    int lim = sqrt(m + 1);
    for(int i = 2; i <= lim; i++) {
      while(x % i == 0) {
        mp[i]++;
        x /= i;
      }
    }
    if(x > 1) mp[x]++;

    for(auto i: mp) {
      x = n;
      int power = 0;
      while(x) {
        power += (x / i.first);
        x /= i.first;
      }
      mp2[i.first] = power / i.second;
    }

    cout << "Case " << ++cs << ":\n";
    int ans = INT_MAX;
    for(auto i: mp2) {
      ans = min(ans, i.second);
    }
    if(ans == 0) {
      cout << "Impossible to divide\n";
    }
    else {
      cout << ans << '\n';
    }
  }

  return 0;
}