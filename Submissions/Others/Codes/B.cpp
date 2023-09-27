#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);


  int n; cin >> n;
  vector<pair<string, int>> a;
  for(int i = 1; i <= n; i++) {
    string s; int x; cin >> s >> x;
    a.push_back({s, x});
  }

  int ans = 0;
  for(int i = 1; i <= 100; i++) {
    int val = i;
    for(auto j: a) {
      if(j.first == "ADD") {
        val += j.second;
      }
      else if(j.first == "SUBTRACT") {
        val -= j.second;
        if(val < 0) {
          ans++;
          break;
        }
      }
      else if(j.first == "MULTIPLY") {
        val *= j.second;
      }
      else {
        if(val % j.second != 0) {
          ans++;
          break;
        }
        val /= j.second;
      }
    }
  }
  cout << ans << '\n';

  return 0;
}