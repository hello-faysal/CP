#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 9, inf = N + 123;

struct ST {
  int tree[4 * N], lazy[4 * N];
  void push(int n, int b, int e) {
    if (lazy[n] == inf) return;
    tree[n] = min(tree[n], lazy[n]);
    if (b != e) {
      int l = n << 1, r = l + 1;
      lazy[l] = min(lazy[l], lazy[n]);
      lazy[r] = min(lazy[r], lazy[n]);
    }
    lazy[n] = inf;
  }
  void build(int n, int  b, int e) {
    lazy[n] = inf;
    if (b == e) {
      tree[n] = inf;
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n] = min(tree[l], tree[r]);
  }
  void upd(int n, int b, int e, int i, int j, int x) {
    push(n, b, e);
    if (b > j || e < i) return;
    if (b >= i && e <= j) {
      lazy[n] = min(lazy[n], x);
      push(n, b, e);
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    upd(l, b, mid, i, j, x);
    upd(r, mid + 1, e, i, j, x);
    tree[n] = min(tree[l], tree[r]);
  }
  int query(int n, int b, int e, int i, int j) {
    push(n, b, e);
    if (b > j || e < i) return inf;
    if (b >= i && e <= j) return tree[n];
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    int L = query(l, b, mid, i, j);
    int R = query(r, mid + 1, e, i, j);
    return min(L, R);
  }
} st;

void solve() {
  int n; cin >> n;
  int a[n + 1];
  map<int, int> mp;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (mp.find(a[i]) == mp.end()) {
      mp[a[i]] = i;
    }
  }

  st.build(1, 1, n + 2);

  for (int i = 0; i <= n; i++) {
    int x;
    if (mp.find(i) == mp.end()) {
      x = n;
    }
    else {
      x = mp[i];
    }
    // cout << i << ": " << x << '\n';
    st.upd(1, 1, n + 2, 1, x, i);
  }

  int mex = 0;
  for (int i = 1; i <= n; i++) {
    int y = min(a[i], st.query(1, 1, n + 2, i, i));
    if (y == mex) mex++;
    cout << min(y, mex) << ' ';
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