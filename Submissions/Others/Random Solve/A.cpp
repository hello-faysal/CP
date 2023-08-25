#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  vector<int> v(209, 0);
  int mx = -1;
  for(int i = 0; i < n; i++) {
    int x; cin >> x;
    v[x]++;
    mx = max(mx, x);
  }

  bool possible = true;
  for(int i = 1; i <= mx; i++) {
    if(v[i] == 0) {
      possible = false;
      cout << i << '\n';
    }
  }

  if(possible) {
    cout << "good job\n";
  }

  return 0;
}