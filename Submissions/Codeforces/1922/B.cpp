#include <bits/stdc++.h>
using namespace std;

#define int long long
int get(int x) {
  return (x * (x + 1)) / 2;
}

void solve() {
  int n; cin >> n;
  int a[n + 1];
  map<int, int> mp;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    mp[a[i]]++;
  }

  sort(a + 1, a + n + 1);

  long long ans = 0;
  for (int i = n; i >= 3; i--) {
    mp[a[i]]--;
    int left = i - 1;
    if (mp[a[i]] == 0) continue;
    int start = (left - mp[a[i]]);
    int end = (left - 1);
    ans += get(end);
    if (start > 0) {
      ans -= get(start - 1);
    }
  }
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