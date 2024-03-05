#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


int cs = 0;
void solve() {
  int n, q; cin >> n >> q;
  map<int, int> mp;
  o_set<int> se;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    mp[i] = x;
    se.insert(i);
  }
  int id = n;
  cout << "Case " << ++cs << ":\n";
  while (q--) {
    char c; int k; cin >> c >> k;
    if (c == 'a') {
      mp[++id] = k;
      se.insert(id);
    }
    else {
      if (se.size() < k) {
        cout << "none\n";
      }
      else {
        int x = *se.find_by_order(k - 1);
        cout << mp[x] << '\n';
        se.erase(x);
      }
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}