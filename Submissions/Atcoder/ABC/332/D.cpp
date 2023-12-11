#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T> using o_set = tree<T, null_type, greater<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 7;
int n, m, a[N][N], b[N][N];
bool rows[N], cols[N];
int row[N], col[N];

bool find_row(int idx) {
  map<int, int> mp;
  for (int j = 1; j <= m; j++) {
    mp[a[idx][j]]++;
  }

  for (int i = 1; i <= n; i++) {
    map<int, int> mp2;
    for (int j = 1; j <= m; j++) {
      mp2[b[i][j]]++;
    }
    if (mp == mp2 and !rows[i]) {
      row[idx] = i;
      rows[i] = true;
      return true;
    }
  }
  return false;
}

bool find_col(int idx) {
  map<int, int> mp;
  for (int i = 1; i <= n; i++) {
    mp[a[i][idx]]++;
  }
  for (int j = 1; j <= m; j++) {
    map<int, int> mp2;
    for (int i = 1; i <= n; i++) {
      mp2[b[i][j]]++;
    }
    if (mp == mp2 and !cols[j]) {
      col[idx] = j;
      cols[j] = true;
      return true;
    }
  }
  return false;
}

bool is_valid() {
  for (int i = 1; i <= n; i++) {
    if (!find_row(i)) {
      return false;
    }
  }

  for (int j = 1; j <= m; j++) {
    if (!find_col(j)) {
      return false;
    }
  }
  
  return true;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> b[i][j];
    }
  }

  if (!is_valid()) {
    cout << -1 << '\n';
    return 0;
  }

  o_set<int> se;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += se.order_of_key(row[i]);
    se.insert(row[i]);
  }

  se.clear();
  for (int j = 1; j <= m; j++) {
    ans += se.order_of_key(col[j]);
    se.insert(col[j]);
  }

  cout << ans << '\n';

  return 0;
}