#include <bits/stdc++.h>
using namespace std;

int cs = 0;
void solve() {
  int n, a, b; cin >> n >> a >> b;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  sort(arr.begin(), arr.end());
  long long ans = 0;
  for (int i = 1; i < n; i++) {
    int y1 = a - arr[i];
    int y2 = b - arr[i];
    auto start = lower_bound(arr.begin(), arr.begin() + i, y1);
    auto end = upper_bound(arr.begin(), arr.begin() + i, y2);
    ans += end - start;
  }
  cout << "Case " << ++cs << ": " << ans << '\n';
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