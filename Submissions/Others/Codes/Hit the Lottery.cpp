#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  int ans = n / 100;
  n %= 100;
  ans += n / 20;
  n %= 20;
  ans += n / 10;
  n %= 10;
  ans += n / 5;
  n %= 5;
  ans += n / 1;
  n %= 1;

  cout << ans << '\n';

  return 0;
}