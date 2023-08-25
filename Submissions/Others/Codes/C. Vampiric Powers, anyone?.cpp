#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  int curr_xor = 0, ans = -1;
  for(int i = 0; i < n; i++) {
    int x; cin >> x;
    curr_xor ^= x;
    ans = max(ans, curr_xor);
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}