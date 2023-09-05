#include <bits/stdc++.h>
using namespace std;

// @author: faysalahammedchowdhury

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while(t--) {
    unsigned long long a, b; cin >> a >> b;
    unsigned __int128 x = (unsigned __int128) a * b;
    int ans = x % 100;
    cout << ans << '\n';
  }

  return 0;
}