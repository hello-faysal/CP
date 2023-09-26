#include <bits/stdc++.h>
using namespace std;

const int N = 105, inf = 1e9;
vector<int> g[N];
vector<int> dis(N, inf);
vector<bool> vis(N, false);

void bfs(int u) {
  vis[u] = true;
  dis[u] = 0;
  queue<int> q;
  q.push(u);
  while(!q.empty()) {
    int top = q.front(); q.pop();
    for(auto v: g[top]) {
      if(!vis[v]) {
        vis[v] = true;
        q.push(v);
        dis[v] = dis[top] + 1;
      }
    }
  }
}


int cs = 0;
void solve() {
  cout << "Case " << ++cs << ": ";
  int n, m; cin >> n >> m;
  for(int i = 1; i <= n; i++) {
    g[i].clear();
    vis[i] = false;
    dis[i] = inf;
  }
  while(m--) {
    int u, v; cin >> u >> v;
    u++, v++;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  int a, b; cin >> a >> b;
  a++, b++;
  bfs(a);
  int mx1 = -inf;
  for(int i = 1; i <= n; i++) {
    if(i != b) {
      mx1 = max(mx1, dis[i]);
    }
  }

  for(int i = 1; i <= n; i++) {
    dis[i] = inf;
    vis[i] = false;
  }

  bfs(b);
  int mx2 = -inf;
  for(int i = 1; i <= n; i++) {
    if(i != a) {
      mx2 = max(mx2, dis[i]);
    }
  }

  cout << max(1, mx1 + mx2) << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}