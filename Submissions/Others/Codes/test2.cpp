#include <bits/stdc++.h>
using namespace std;

int n;
const int N = 10;

void fun(int i, int last, vector<int> &a) {
  if (i == n + 1) {
    int g = 0, sum = 0;
    for (int j = 1; j <= n; j++) {
      g = __gcd(g, a[j]);
      sum += a[j];
    }
    if (g == 1) {
      for (int j = 1; j <= n; j++) {
        if (__gcd(a[j], sum - a[j]) == 1) {
          return;
        }
      }
      for (int j = 1; j <= n; j++) {
        cout << a[j] << ' ';
      }
      cout << '\n';
    }
    return;
  }

  for (int j = last + 1; j <= 30000; j++) {
    a[i] = j;
    fun(i + 1, j, a);
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  vector<int> a(N);

  cin >> n;

  for (int i = 1; i < n; i++) {
    a[i] = i + 1;
  }

  fun(1, 1, a);

  return 0;
}