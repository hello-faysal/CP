#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash {
  int operator()(pair<int, int> x) const { return x.first ^ x.second ^ RANDOM; }
};

const int N = 1009; // change here

int power(long long n, long long k, const int mod) {
  int ans = 1 % mod;
  n %= mod;
  if (n < 0) n += mod;
  while (k) {
    if (k & 1) ans = (long long) ans * n % mod;
    n = (long long) n * n % mod;
    k >>= 1;
  }
  return ans;
}

const int MOD1 = 127657753, MOD2 = 987654319;
const int p1 = 137, p2 = 277; // change here
int ip1, ip2;
pair<int, int> pw[N], ipw[N];
void prec() {
  pw[0] = {1, 1};
  for (int i = 1; i < N; i++) {
    pw[i].first = 1ll * pw[i - 1].first * p1 % MOD1;
    pw[i].second = 1ll * pw[i - 1].second * p2 % MOD2;
  }
  ip1 = power(p1, MOD1 - 2, MOD1);
  ip2 = power(p2, MOD2 - 2, MOD2);
  ipw[0] = {1, 1};
  for (int i = 1; i < N; i++) {
    ipw[i].first = 1ll * ipw[i - 1].first * ip1 % MOD1;
    ipw[i].second = 1ll * ipw[i - 1].second * ip2 % MOD2;
  }
}

struct Hashing {
  int n;
  string s;
  vector<pair<int, int>> hash_val;
  Hashing() {}
  Hashing(string _s) {
    s = _s;
    n = s.size();
    hash_val.emplace_back(0, 0);
    for (int i = 0; i < n; i++) {
      pair<int, int> p;
      p.first = (hash_val[i].first + 1ll * s[i] * pw[i].first % MOD1) % MOD1;
      p.second = (hash_val[i].second + 1ll * s[i] * pw[i].second % MOD2) % MOD2;
      hash_val.push_back(p);
    }
  }

  pair<int, int> get_hash(int l, int r) { // 1 indexed
    pair<int, int> ans;
    ans.first = (hash_val[r].first - hash_val[l - 1].first + MOD1) * 1ll * ipw[l - 1].first % MOD1;
    ans.second = (hash_val[r].second - hash_val[l - 1].second + MOD2) * 1ll * ipw[l - 1].second % MOD2;
    return ans;
  }
  pair<int, int> get_hash() { // 1 indexed
    return get_hash(1, n);
  }
};

int n;
string a[105];
Hashing hs[105];
gp_hash_table<pair<int, int>, bool, chash> final;

bool ok(int len) {
  final.clear();
  gp_hash_table<pair<int, int>, int, chash> mp;
  for (int i = 1; i <= n; i++) {
    gp_hash_table<pair<int, int>, bool, chash> se;
    for (int j = 1; j + len - 1 <= a[i].length(); j++) {
      se[hs[i].get_hash(j, j + len - 1)] = true;
    }
    for (auto [x, y] : se) {
      mp[x]++;
    }
  }
  bool flag = false;
  for (auto [x, cnt] : mp) {
    if (cnt > (n / 2)) {
      final[x] = true;
      flag = true;
    }
  }
  return flag;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  prec();

  while (cin >> n and n != 0) {
    int sz = 10000;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      hs[i] = Hashing(a[i]);
      sz = min(sz, (int)a[i].size());
    }

    int l = 0, r = sz, len = -1;
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (ok(mid)) {
        len = mid;
        l = mid + 1;
      }
      else {
        r = mid - 1;
      }
    }

    if (len == 0) {
      cout << "?\n";
      cout << '\n';
      continue;
    }

    ok(len);

    vector<string> ans;
    for (auto [x, y] : final) {
      for (int i = 1; i <= n; i++) {
        bool flag = false;
        for (int j = 1; j + len - 1 <= a[i].length(); j++) {
          if (hs[i].get_hash(j, j + len - 1) == x) {
            ans.push_back(a[i].substr(j - 1, len));
            flag = true;
            break;
          }
        }
        if (flag) break;
      }
    }

    sort(ans.begin(), ans.end());

    for (auto x : ans) {
      cout << x << '\n';
    }
    cout << '\n';
  }

  return 0;
}