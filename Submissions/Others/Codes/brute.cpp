#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, x; cin >> n >> x;
  int a[n + 1];
  a[0] = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a[i] += a[i - 1];
  }

  int ans = - 1;
  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j++) {
      int sum = a[j] - a[i - 1];
      if (sum % x != 0) {
        ans = max(ans, j - i + 1);
      }
    }
  }
  cout << ans << '\n';
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