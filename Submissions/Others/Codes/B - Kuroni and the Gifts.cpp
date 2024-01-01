#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  vector<int> a(n), b(n), c(n);
  for (auto &x : a) {
    cin >> x;
  }
  for (auto &x : b) {
    cin >> x;
  }
  c = b;
  sort(a.begin(), a.end());
  sort(c.begin(), c.end());
  map<int, int> mp;
  for (int i = 0; i < n; i++) {
    mp[c[i]] = a[i];
  }
  for (int i = 0; i < n; i++) {
    cout << mp[b[i]] << ' ';
  }
  cout << '\n';
  for (auto x : b) {
    cout << x << ' ';
  }
  cout << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}