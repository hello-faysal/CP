#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
int power(int x, long long n, int mod) {
  int ans = 1 % mod;
  while (n > 0) {
    if (n & 1) {
      ans = 1LL * ans * x % mod;
    }
    x = 1LL * x * x % mod;
    n >>= 1;
  }
  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  int x = 3 * n;
  int ans = (((power(3, x, mod) - power(7, n, mod)) % mod) + mod) % mod;
  cout << ans << '\n';
}