#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
  int n; cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int mx1 = 0, mn1 = 0, mx2 = a[1], mn2 = a[1];
  long long ans = 0;
  for (int i = 2; i <= n; i++) {
    if (a[i] > a[i - 1]) {
      ans += mx2 - mn1;
      mn1 = mn2;
      mn2 = a[i], mx2 = a[i];
    }
    else {
      mx2 = max(mx2, a[i]);
      mn2 = min(mn2, a[i]);
    }
  }
  ans += mx2 - mn1;
  ans -= 1;

  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}