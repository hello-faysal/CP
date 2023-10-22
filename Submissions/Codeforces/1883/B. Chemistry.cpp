#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, k; cin >> n >> k;
  string s; cin >> s;

  if (n == 1) {
    cout << "Yes\n";
    return;
  }

  map<char, int> mp;
  for (auto c : s) {
    mp[c]++;
  }

  int even = 0, odd = 0;
  for (auto i : mp) {
    if (i.second & 1) odd++;
    else even++;
  }

  if (odd > k + 1) {
    cout << "No\n";
    return;
  }

  if (odd == k or odd == k + 1) {
    cout << "Yes\n";
    return;
  }

  int must = odd - 1;
  int x = k - must;
  if (x % 2 == 0) {
    cout << "Yes\n";
    return;
  }

  x = k - odd;
  if (x % 2 == 0) {
    cout << "Yes\n";
    return;
  }

  cout << "No\n";
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