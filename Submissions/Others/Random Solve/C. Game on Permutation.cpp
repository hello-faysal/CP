#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    int a[n + 1];
    int move[n + 1];
    memset(move, 0, sizeof(move));
    for(int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    int cnt = 0;
    for(int i = 1; i <= n; i++) {
      for(int j = 1; j < i; j++) {
        if(a[j] < a[i]) {
          move[a[i]] = max(move[a[i]], move[a[j]] + 1);
        }
      }
      if(move[a[i]] == 1) cnt++;
    }
    cout << cnt << '\n';
  }

  return 0;
}