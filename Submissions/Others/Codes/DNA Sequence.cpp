#include <bits/stdc++.h>
using namespace std;

const int N = 17;
int n, tail[N][N], dp[(1 << N) + 2][N + 2];
string s[N + 2];

int fun(int mask, int last) {
  if (__builtin_popcount(mask) >= n) {
    return 0;
  }

  int &ans = dp[mask][last];
  if (ans != -1) return ans;

  ans = 1e9;
  for (int j = 1; j <= n; j++) {
    if (!(mask & (1 << j))) {
      if (last == n + 1) {
        int x = s[j].length() + fun(mask | (1 << j), j);
        ans = min(ans, x);
      }
      else {
        int x = (s[j].length() - tail[last][j]) + fun(mask | (1 << j), j);
        ans = min(ans, x);
      }
    }
  }

  return ans;
}


void print(int mask, int last) {
  if (__builtin_popcount(mask) >= n) {
    return;
  }

  int ans = 1e9, idx = 0;
  for (int j = 1; j <= n; j++) {
    if (!(mask & (1 << j))) {
      if (last == n + 1) {
        int x = s[j].length() + fun(mask | (1 << j), j);
        if (x < ans) {
          idx = j;
          ans = x;
        }
      }
      else {
        int x = (s[j].length() - tail[last][j]) + fun(mask | (1 << j), j);
        if (x < ans) {
          idx = j;
          ans = x;
        }
      }
    }
  }

  if (last == n + 1) {
    cout << s[idx];
  }
  else {
    cout << s[idx].substr(tail[last][idx]);
  }
  return print(mask | (1 << idx), idx);
}

int cs = 0;
void solve() {
  cin >> n;
  set<string> se;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
    se.insert(s[i]);
  }

  // remove duplicates
  n = se.size();
  int id = 1;
  for (auto x : se) {
    s[id++] = x;
  }

  // remove "a[i]" if it is a substring of "a[j]"
  vector<string> vec;
  for (int i = 1; i <= n; i++) {
    string x = s[i];
    bool ok = true;
    for (int j = 1; j <= n; j++) {
      if (i == j) continue;
      string y = s[j];
      for (int k = 0; k + x.length() <= y.length(); k++) {
        if (x == y.substr(k, x.length())) {
          ok = false;
          break;
        }
      }
      if (ok == false) {
        break;
      }
    }
    if (ok) {
      vec.push_back(x);
    }
  }

  n = vec.size();
  int idx = 1;
  for (auto x : vec) {
    s[idx++] = x;
  }

  // sort by lexicographically so that we will get the lexicographically min string
  sort(s + 1, s + n + 1);

  // maximum length that suffix of a[i] = prefix of a[j]
  memset(tail, 0, sizeof(tail));
  for (int i = 1; i <= n; i++) {
    string x = s[i];
    for (int j = 1; j <= n; j++) {
      string y = s[j];
      int cnt = 0;
      for (int k = min(x.length(), y.length()); k >= 1; k--) {
        if (x.substr(x.length() - k) == y.substr(0, k)) {
          cnt = k;
          break;
        }
      }
      tail[i][j] = cnt;
    }
  }


  // dp and print the string
  memset(dp, -1, sizeof(dp));
  fun(0, n + 1);
  cout << "Case " << ++cs << ": ";
  print(0, n + 1);
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