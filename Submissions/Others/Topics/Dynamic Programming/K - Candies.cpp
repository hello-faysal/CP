#include <bits/stdc++.h>
using namespace std;

const int N = 105, K = 1e5 + 9, mod = 1e9 + 7;
int n, k, a[N];

int fun(int i, int remaining) {
  if (i == n + 1) {
    if (remaining == 0) return 1;
    return 0;
  }
  int ans = 0;
  for (int j = 0; j <= a[i]; j++) {
    ans += fun(i + 1, remaining - j);
  }
  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  cout << fun(1, k) << '\n';

  return 0;
}