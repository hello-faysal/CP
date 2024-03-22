#include <bits/stdc++.h>
using namespace std;

#define int long long
const int mod = 1e9 + 7;
using ll = long long;

int power(int b, int p, int m) {
  if(p == 0) return 1 % m;
  if(p & 1) {
    int val = power(b, p / 2, m);
    return ((1LL * val * val) % m) * b % m;
  }
  else {
    int val = power(b, p / 2, m);
    return (1LL * val * val) % m;
  }
}

void solve() {
  int n, k; cin >> n >> k;
  ll a[n + 1];
  a[0] = 0;
  ll sum = 0;
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
    sum += a[i];
    sum %= mod;
  }
  for(int i = 1; i <= n; i++) {
    a[i] += a[i - 1];
  }
  ll low = 0;
  ll ans = -1e18;
  for(int i = 1; i <= n; i++) {
    ans = max(ans, a[i] - low);
    low = min(low, a[i]);
  }
  ans = max(0ll, ans);
  ans %= mod;

  if (sum < 0) sum += mod;

  ll series = (ans == 0 ? 0 : 1ll * ans * ((((power(2, k, mod) - 1) % mod) + mod) % mod) % mod);
  series %= mod;
  sum = (sum + series) % mod;
  cout << sum << '\n';
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