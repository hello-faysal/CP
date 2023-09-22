#include <bits/stdc++.h>
using namespace std;

// @author: faysalahammedchowdhury

const int N = 1e5 + 9;
vector<int> g[N];
vector<bool> vis(N, false);
int n, m, consecutive, a[N];
int ans;

void dfs(int u, int par, int cnt) {
  vis[u] = true;
  
  if(a[par] == 1 && a[u] == 1) cnt++;
  else if(a[u] == 1) cnt = 1;
  else cnt = 0;

  if(cnt > consecutive) return;

  bool leaf = true;
  for (auto v: g[u]) {
    if (!vis[v]) {
      leaf = false;
      dfs(v, u, cnt);
    }
  }

  if(leaf) ans++;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> consecutive;
  m = n - 1;
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  while(m--) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  dfs(1, 0, 0);

  cout << ans << '\n';

  return 0;
}