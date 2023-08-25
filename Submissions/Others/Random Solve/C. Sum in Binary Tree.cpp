#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve() {
  long long n; cin >> n;
  long long sum = n;
  while(n > 0) {
    long long got = n / 2;
    sum += got;
    n = n / 2;
  }
  cout << sum << '\n';
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}