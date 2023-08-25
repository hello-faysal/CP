#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while(t--) {
    int n; cin >> n;

    // sol-1
    // int ans = 1;
    // for(int i = 2; i * i <= n; i++) {
    //   while(n % i == 0) {
    //     int p = i, pw = 1;
    //     while(n % p == 0) {
    //       pw *= p;
    //       n /= p;
    //     }
    //     ans *= pw - (pw / p); // (p^e) - (p^(e-1))
    //   }
    // }
    // if(n > 1) {
    //   int p = n, pw = n;
    //   ans *= pw - (pw / p);
    // }
    // cout << ans << '\n';

    // sol-2 (n * ((p1 - 1 ) / p1) * ((p2 - 1 ) / p2))
    int ans = n;
    for(int i = 2; i * i <= n; i++) {
      while(n % i == 0) {
        int p = i;
        while(n % p == 0) {
          n /= p;
        }
        ans *= (p - 1) / (double)p;
      }
    }
    if(n > 1) {
      int p = n;
      ans *= (p - 1) / (double)p;
    }
    cout << ans << '\n';
  }

  return 0;
}
