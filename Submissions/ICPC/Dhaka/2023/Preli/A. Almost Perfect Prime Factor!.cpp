#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9, MAX_VAL = 1e6 + 9;
int spf[MAX_VAL];

void spf_sieve() {
  for(int i = 2; i < MAX_VAL; i++) {
    spf[i] = i;
  }
  for(int i = 2; i < MAX_VAL; i++) {
    if(spf[i] == i) {
      for(int j = i; j < MAX_VAL; j += i) {
        spf[j] = min(spf[j], i);
      }
    }
  }
}

int a[N];

struct ST {
  int tree[4 * N];
  void build(int n, int b, int e) {
    if(b == e) {
      tree[n] = a[b]; // change here
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n] = __gcd(tree[l], tree[r]); // change here
  }
  int query(int n, int b, int e, int i, int j) {
    if(b > j || e < i) return 0; // return appropriate value
    if(b >= i && e <= j) return tree[n];
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    int L = query(l, b, mid, i, j);
    int R = query(r, mid + 1, e, i, j);
    return __gcd(L, R); // change this
  }
} st;

void solve() {
  int n, k; cin >> n >> k;
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  st.build(1, 1, n);

  map<int, int> mp;
  int ans = 0;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  spf_sieve();

  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}