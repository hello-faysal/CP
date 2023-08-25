#include <bits/stdc++.h>
using namespace std;

string s, l, r;
int m;
vector<char> arr[10];

bool is_subsequence(string s, string p) {
  int len = s.size();
  int curr_idx = 0;
  for(int i = 0; i < len && curr_idx < m; i++) {
    if(s[i] == p[curr_idx]) {
      curr_idx++;
    }
  }
  if(curr_idx < m) {
    return false;
  }
  return true;
}

bool fun(int pos, string &curr) {
  if(pos == m) {
    // if(!is_subsequence(s, curr)) {
    //   return true;
    // }
    cout << curr << '\n';
    return false;
  }
  for(auto i: arr[pos]) {
    curr.push_back(i);
    bool ans = fun(pos + 1, curr);
    if(ans) return true;
    curr.pop_back();
  }

  return false;
}

void solve() {
  for(int i = 0; i < 10; i++) {
    arr[i].clear();
  }
  cin >> s >> m >> l >> r;
  for(int i = 0; i < m; i++) {
    for(char j = l[i]; j <= r[i]; j++) {
      arr[i].push_back(j);
    }
  }

  // for(int i = 0; i < m; i++) {
  //   cout << i << ": ";
  //   for(auto j: arr[i]) {
  //     cout << j << ' ';
  //   }
  //   cout << '\n';
  // }
  string curr = "";
  if(fun(0, curr)) {
    cout << "YES\n";
  }
  else {
    cout << "NO\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}