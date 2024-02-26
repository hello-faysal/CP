#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9, mod = 1e9 + 7;
int fact[N];

void prec() {
  fact[0] = 1;
  for (int i = 1; i < N; i++) {
    fact[i] = 1ll * fact[i - 1] * i % mod;
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  prec();

  int n, m; cin >> n >> m;
  if (n > m) swap(n, m);

  if (n == m) {
    int ans = 1ll * fact[n] * fact[m] % mod;
    ans = 2 * ans % mod;
    cout << ans << '\n';
  }
  else if (m - n == 1) {
    int ans = 1ll * fact[n] * fact[m] % mod;
    cout << ans << '\n';
  }
  else {
    cout << 0 << '\n';
  }

  return 0;
}