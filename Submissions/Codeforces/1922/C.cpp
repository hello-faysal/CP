#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 1e5 + 9;
int a[N], b[N];

struct ST {
  int tree[4 * N];
  void build(int n, int b, int e) {
    if(b == e) {
      tree[n] = 0;
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n] = tree[l] + tree[r];
  }
  void upd(int n, int b, int e, int i, int x) {
    if(b > i || e < i) return;
    if(b == e && b == i) {
      tree[n] = x;
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    upd(l, b, mid, i, x);
    upd(r, mid + 1, e, i, x);
    tree[n] = tree[l] + tree[r];
  }
  int query(int n, int b, int e, int i, int j) {
    if(b > j || e < i) return 0; 
    if(b >= i && e <= j) return tree[n];
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    int L = query(l, b, mid, i, j);
    int R = query(r, mid + 1, e, i, j);
    return (L + R); 
  }
} st, st2;

int get(int i, int n) {
  return n - i + 1;
}

void solve() {
  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    b[i] = a[i];
  }

  reverse(b + 1, b + n + 1);

  st.build(1, 1, n);
  st.upd(1, 1, n, 1, 1);
  for (int i = 2; i < n; i++) {
    if (abs(a[i] - a[i + 1]) <= abs(a[i] - a[i - 1])) {
      st.upd(1, 1, n, i, 1);
    }
    else {
      st.upd(1, 1, n, i, a[i + 1] - a[i]);
    }
  }


  st2.build(1, 1, n);
  st2.upd(1, 1, n, 1, 1);
  for (int i = 2; i < n; i++) {
    if (abs(b[i] - b[i + 1]) <= abs(b[i] - b[i - 1])) {
      st2.upd(1, 1, n, i, 1);
    }
    else {
      st2.upd(1, 1, n, i, abs(b[i + 1] - b[i]));
    }
  }

  int m; cin >> m;
  while (m--) {
    int l, r; cin >> l >> r;
    if (l == r) {
      cout << 0 << '\n';
    }
    else if (l < r) {
      cout << st.query(1, 1, n, l , r - 1) << '\n';
    }
    else {
      l = get(l, n);
      r = get(r, n);
      cout << st2.query(1, 1, n, l , r - 1) << '\n';
    }
  }
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