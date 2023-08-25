#include <bits/stdc++.h>
using namespace std;

void solve() {
  int i1, j1, i2, j2; cin >> i1 >> j1 >> i2 >> j2;
  int x_distance = abs(i1 -i2), y_distance = abs(j1 - j2);
  x_distance = min(x_distance, i1 + (16 - i2));
  x_distance = min(x_distance, (16 - i1) + i2);
  y_distance = min(y_distance, j1 + (20 - j2));
  y_distance = min(y_distance, (20 - j1) + j2);
  int ans = x_distance + y_distance;
  cout << ans  << '\n';
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}