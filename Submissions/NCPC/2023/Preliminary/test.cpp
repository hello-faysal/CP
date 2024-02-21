#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;
int a[N];

struct ST {
  int tree[4 * N], lazy[4 * N];
  void push(int n, int b, int e) {
    if (lazy[n] == 0) return;
    tree[n] = lazy[n];
    if (b != e) {
      int l = n << 1, r = l + 1;
      lazy[l] = lazy[n];
      lazy[r] = lazy[n];
    }
    lazy[n] = 0;
  }
  void build(int n, int  b, int e) {
    lazy[n] = 0;
    if (b == e) {
      tree[n] = 0;
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n] = max(tree[l], tree[r]);
  }
  void upd(int n, int b, int e, int i, int j, int x) {
    push(n, b, e);
    if (b > j || e < i) return;
    if (b >= i && e <= j) {
      lazy[n] = x;
      push(n, b, e);
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    upd(l, b, mid, i, j, x);
    upd(r, mid + 1, e, i, j, x);
    tree[n] = max(tree[l], tree[r]);
  }
  int query(int n, int b, int e, int i, int j) {
    push(n, b, e);
    if (b > j || e < i) return 0;
    if (b >= i && e <= j) return tree[n];
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    int L = query(l, b, mid, i, j);
    int R = query(r, mid + 1, e, i, j);
    return max(L, R);
  }

  int get_first(int n, int b, int e, int l, int r, int x) {
    if (b > r || e < l) return -1;
    if (tree[n] <= x) return -1;

    if (b == e) return b;

    int tm = b + (e - b) / 2;
    int left = get_first(2 * n, b, tm, l, r, x);
    if (left != -1) return left;
    return get_first(2 * n + 1, tm + 1, e, l , r, x);
  }
} st;

struct ST2 {
  int tree[4 * N], lazy[4 * N];
  void push(int n, int b, int e) {
    if (lazy[n] == 0) return;
    tree[n] = lazy[n] * (e - b + 1);
    if (b != e) {
      int l = n << 1, r = l + 1;
      lazy[l] = lazy[n];
      lazy[r] = lazy[n];
    }
    lazy[n] = 0;
  }
  void build(int n, int  b, int e) {
    lazy[n] = 0;
    if (b == e) {
      tree[n] = 0;
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n] = tree[l] + tree[r];
  }
  void upd(int n, int b, int e, int i, int j, int x) {
    push(n, b, e);
    if (b > j || e < i) return;
    if (b >= i && e <= j) {
      lazy[n] += x;
      push(n, b, e);
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    upd(l, b, mid, i, j, x);
    upd(r, mid + 1, e, i, j, x);
    tree[n] = tree[l] + tree[r];
  }
  int query(int n, int b, int e, int i, int j) {
    push(n, b, e);
    if (b > j || e < i) return 0;
    if (b >= i && e <= j) return tree[n];
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    int L = query(l, b, mid, i, j);
    int R = query(r, mid + 1, e, i, j);
    return L + R;
  }
} st2;

int n;
vector<int> g[N];
int ans[N];

void dfs(int u, int p, int lvl) {
  int idx = st.get_first(1, 1, n, 1, lvl - 1, -a[u]);
  if (idx == -1) {
    st.upd(1, 1, n, lvl, lvl, -a[u]);
    st2.upd(1, 1, n, lvl, lvl, a[u]);
    ans[u] = st2.query(1, 1, n, 1, lvl);
  }
  else {
    st.upd(1, 1, n, idx, lvl, -a[u]);
    st2.upd(1, 1, n, idx, lvl, a[u]);
    ans[u] = st2.query(1, 1, n, 1, lvl);
  }

  for (auto v : g[u]) {
    if (v != p) {
      dfs(v, u, lvl + 1);
    }
  }
  st.upd(1, 1, n, lvl, lvl, 0);
  st2.upd(1, 1, n, lvl, lvl, 0);
}

int cs = 0;
void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    g[i].clear();
    ans[i] = 0;
  }
  int m = n - 1;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  while (m--) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  st.build(1, 1, n);
  st2.build(1, 1, n);

  dfs(1, 0, 1);

  cout << "Case " << ++cs << ":\n";
  for (int u = 1; u <= n; u++) {
    cout << ans[u];
    if (u != n) {
      cout << ' ';
    }
  }
  cout << '\n';
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