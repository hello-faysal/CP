#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  if (n == 1) {
    cout << -1 << '\n';
    return;
  }
  cout << 2;
  for (int i = 2; i <= n; i++) {
    cout << 3;
  }
  cout << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}