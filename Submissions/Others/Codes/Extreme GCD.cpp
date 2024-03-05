#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 1e4 + 9;

ll nC4(int n) {
  return (1ll * n * (n - 1) * (n - 2) * (n - 3)) / 24;
}

int cs = 0;
void solve() {
  int n; cin >> n;
  int a[n + 1];
  int div_cnt[N];
  memset(div_cnt, 0, sizeof div_cnt);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    for (int j = 1; j * j <= a[i]; j++) {
      if (a[i] % j == 0) {
        div_cnt[j]++;
        if (j != a[i] / j) {
          div_cnt[a[i] / j]++;
        }
      }
    }
  }

  ll ans[N];
  for (int i = N - 1; i >= 1; i--) {
    ans[i] = nC4(div_cnt[i]);
    for (int j = i + i; j < N; j += i) {
      ans[i] -= ans[j];
    }
  }

  cout << "Case " << ++cs << ": ";
  cout << ans[1] << '\n';
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