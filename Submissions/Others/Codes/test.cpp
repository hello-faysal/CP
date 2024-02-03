#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int m, k; cin >> m >> k;
  vector<int> v;
  int n = (1 << (m + 1));
  int x = (1 << m) - 1;
  for (int i = 0; i <= x; i++) {
    v.push_back(i);
    v.push_back(i);
  }

  do {
    bool ok = true;
    for (int i = 0; i < n; i++) {
      int y = v[i];
      int xr = 0;
      bool paisi = false;
      for (int j = i + 1; j < n; j++) {
        if (v[j] == y) {
          paisi = true;
          break;
        }
        xr ^= v[j];
      }
      if (paisi) {
        ok &= xr == k;
      }
    }
    if (ok) {
      for (auto l : v) {
        bitset<5> bs(l);
        cout << l << ' ';
      }
      cout << '\n';
    }
  } while (next_permutation(v.begin(), v.end()));
  //

  return 0;
}