#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 1e5 + 9;
int a[N];
vector<int> g[N];
vector<bool> vis(N, false);

void dfs(int u, set<pair<int, int>> &se, int x) {
  se.insert({x, a[u]});
  vis[u] = true;
  for (auto v: g[u]) {
    if (!vis[v]) {
      dfs(v, se, x);
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m; cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for(int i = 1; i <= m; i++) {
    int u, v; cin >> u >> v;
    u++, v++;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  set<pair<int, int>> se;
  int x = 0;
  for (int u = 1; u <= n; u++) {
    if (!vis[u]) {
      dfs(u, se, ++x);
    }
  }

  int ans = 0;
  for (int i = 2; i <= x; i++) {
    auto f = se.lower_bound({1, -13});
    auto s = se.lower_bound({i, -13});
    if ((*f).first >= (*s).first or f == se.end() or s == se.end()) {
      cout << "Impossible\n";
      return 0;
    }
    ans += (*f).second + (*s).second;
    se.erase(f);
    se.erase(s);
  }

  cout << ans << '\n';

  return 0;
}