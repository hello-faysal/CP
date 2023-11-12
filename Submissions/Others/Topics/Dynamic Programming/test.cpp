#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  long long b; cin >> b;
  for (int i = 1; i <= 15; i++) {
    long long x = 1;
    for (int j = 1; j <= i; j++) {
      x *= i;
    }
    if (x == b) {
      cout << i << '\n';
      return 0;
    }
  }
  cout << -1 << '\n';

  return 0;
}