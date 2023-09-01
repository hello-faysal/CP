#include <bits/stdc++.h>
using namespace std;

// @author: faysalahammedchowdhury

#define int long long
const int N = 1e5 + 9;
int a[N], b[N], cnt[N];

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  int ans = 0;
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
    ans += a[i];
  }
  for(int i = 1; i <= n; i++) {
    cin >> b[i];
  }

  for(int i = 2; i <= n; i++) {
    for(int j = i * i; j <= n; j *= i) {
      cnt[i] += b[j];
      cnt[j] += a[i];
      ans -= b[j];
    }
  }

  for(int i = 1; i <= n; i++) {
    if(a[i] <= cnt[i]) {
      ans -= a[i];
      ans += cnt[i];
    }
  }

  cout << ans << '\n';

  return 0;
}