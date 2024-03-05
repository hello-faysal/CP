#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9, mod = 1000000000 + 7;
int ans[N];

int cs = 0;
void solve() {
  int n; cin >> n;
  cout << "Case " << ++cs << ": ";
  cout << (1ll * ans[n] * n % mod) << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  ans[0] = 1;
  ans[1] = 1;
  ans[2] = 1;
  for (int i = 3; i < N; i++) {
    ans[i] = 1ll * ans[i - 1] * ans[i - 1] % mod * (i - 1) % mod;
  }

  int t = 1; cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}