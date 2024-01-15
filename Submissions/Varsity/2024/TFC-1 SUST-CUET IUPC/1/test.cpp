#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 2e6 + 9, inf = 1e9;
ll n, x, a[N];

int fun(int i, map<int, int> mp) {
  if (i == n + 1) {
    for (auto [x, cnt] : mp) {
      if (cnt > 0) return inf;
    }
    return 0;
  }

  int ans = fun(i + 1, mp);
  int tmp = a[i];
  for (auto [x, cnt] : mp) {
    while (tmp % x == 0) {
      mp[x]--;
      tmp /= x;
      if (mp[x] <= 0) {
        break;
      }
    }
  }
  ans = min(ans, 1 + fun(i + 1, mp));
  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> x;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  map<int, int> mp;
  int lim = sqrt(x + 1);
  for (int i = 2; i <= lim; i++) {
    while (x % i == 0) {
      mp[i]++;
      x /= i;
    }
  }
  if (x > 1) mp[x]++;
  cout << fun(1, mp) << '\n';

  return 0;
}