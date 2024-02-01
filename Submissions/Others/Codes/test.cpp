#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;

  int a[n + 1], mx;
  for (int i = 1; i < n; i++) {
    a[i] = i + 1;
    mx = i + 1;
  }

  int o_g = 0, o_sum = 0;
    for (int j = 1; j < n; j++) {
      o_g = __gcd(o_g, a[j]);
      o_sum += a[j];
    }

  for (int val = mx + 1; val <= 30000; val++) {
    a[n] = val;
    int g = __gcd(o_g, val);
    int sum = o_sum + val;
    if (g == 1) {
      bool flag = false;
      for (int j = 1; j <= n; j++) {
        if (__gcd(a[j], sum - a[j]) == 1) {
          flag = true;
          break;
        }
      }
      if (flag) {
        continue;
      }
      for (int j = 1; j <= n; j++) {
        cout << a[j] << ' ';
      }
      cout << '\n';
      return 0;
    }
  }

  return 0;
}