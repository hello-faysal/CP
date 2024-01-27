#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

gp_hash_table<int, vector<int>> g;
gp_hash_table<int, bool> vis;
int cnt;

void dfs(int u) {
  cnt++;
  vis[u] = true;
  for (auto v : g[u]) {
    if (!vis[v]) {
      dfs(v);
    }
  }
}

void solve() {
  int n, m; cin >> n;
  m = n;
  for (int i = 1; i <= m; i++) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  int ans = 0;
  for (auto [x, _] : g) {
    if (!vis[x]) {
      cnt = 0;
      dfs(x);
      ans = max(ans, cnt);
    }
  }

  cout << ans << '\n';

  g.clear();
  vis.clear();
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}