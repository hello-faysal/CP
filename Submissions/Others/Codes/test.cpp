#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll fact[20];

void prec() {
  fact[0] = 1;
  for (int i = 1; i <= 20; i++) {
    fact[i] = fact[i - 1] * i;
  }
}

bool has_duplicate(vector<int> v) {
  int n = v.size();
  for (int i = 1; i < n; i++) {
    if (v[i] == v[i - 1]) return false;
  }
  return true;
}

bool ok(vector<int> v, ll n) {
  ll ans = 0;
  for (auto x : v) {
    ans += fact[x];
  }
  if (ans != n) return false;
  return has_duplicate(v);
}

int test = 1;
void solve() {
  cout << "Case " << test++ << ": ";
  ll n; cin >> n;
  ll old_n  = n;
  vector<int> v;
  for (int i = 20; i >= 0; i--) {
    if (fact[i] <= n) {
      v.push_back(i);
      n -= fact[i];
    }
  }
  sort(v.begin(), v.end());
  if (!ok(v, old_n)) {
    cout << "impossible\n";
    return;
  }

  int x = v.size();
  for (int i = 0; i < x; i++) {
    cout << v[i] << "!";
    if (i != x - 1) {
      cout << "+";
    }
  }
  cout << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  prec();

  int t; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
