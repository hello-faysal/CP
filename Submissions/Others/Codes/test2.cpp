#include<bits/stdc++.h>
using namespace std;

#define int long long
const int N = 1e7 + 9;

long long get_sum(int x) {
  return (1ll * x * (x + 1)) / 2;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  long long d; cin >> d;

  vector<pair<int, int>> v;
  for (int i = 1; i < N; i++) {
    long long x = get_sum(i);
    long long y = d - x;
    if (y <= 0) break;
    if ((y % i) == 0) {
      v.push_back({y / i, (y / i) + i});
    }
  }

  cout << v.size()<< '\n';
  for (auto [x, y] : v) {
    cout << x << ' ' << y << '\n';
  }

  return 0;
}