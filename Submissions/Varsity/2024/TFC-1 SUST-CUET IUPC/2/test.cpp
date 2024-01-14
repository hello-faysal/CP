#include <bits/stdc++.h>
using namespace std;

#define int long long
void solve() {  
  int a; cin >> a;
  for (int x = 1; x < a; x++) {
    if ((a * x) % (a - x) == 0) {
      cout << (a * x) / (a - x) << '\n';
      break;
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}