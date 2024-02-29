#include <bits/stdc++.h>
using namespace std;

struct Trie {
  const static int N = 2;
  const static char base_char = '0'; // '0' for '0','1','2'
  struct TrieNode {
    int next[N];
    bool is_end;
    int freq;

    TrieNode() {
      for (int i = 0; i < N; i++) {
        next[i] = -1;
      }
      is_end = false;
      freq = 0;
    }
  };

  inline int get(char c) {
    return c - base_char;
  }

  vector<TrieNode> tree;
  Trie() {
    tree.push_back(TrieNode());
  }

  void insert(string s) {
    int p = 0;
    tree[p].freq++;
    for (int i = 0; i < s.size(); i++) {
      if (tree[p].next[get(s[i])] == -1) {
        tree.push_back(TrieNode());
        tree[p].next[get(s[i])] = tree.size() - 1;
      }
      p = tree[p].next[get(s[i])];
      tree[p].freq++;
    }
    tree[p].is_end = true;
  }

  bool is_prefix(const string s) {
    int p = 0;
    for (int i = 0; i < s.size(); i++) {
      if (tree[p].next[get(s[i])] == -1) {
        return false;
      }
      p = tree[p].next[get(s[i])];
    }
    return true;
  }

  bool find(const string s) {
    int p = 0;
    for (int i = 0; i < s.size(); i++) {
      if (tree[p].next[get(s[i])] == -1) {
        return false;
      }
      p = tree[p].next[get(s[i])];
    }
    return tree[p].is_end;
  }

  int maximum_xor(string s) {
    int ans = 0;
    int p = 0;
    for (int i = 0; i < s.size(); i++) {
      if (tree[p].next[get(s[i])] != -1) {
        int bit = s.size() - (i + 1);
        ans += (1 << bit);
        p = tree[p].next[get(s[i])];
      }
      else {
        p = tree[p].next[!get(s[i])];
      }
    }
    return ans;
  }

};

void solve() {
  int n; cin >> n;
  int a[n + 1];
  a[0] = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  Trie trie;
  for (int i = 1; i <= n; i++) {
    a[i] = a[i - 1] ^ a[i];
    bitset<8> bs(a[i]);
    trie.insert(bs.to_string());
  }

  int ans = 0;
  for (int i = 0; i <= n; i++) {
    bitset<8> bs(~a[i]);
    ans = max(ans, trie.maximum_xor(bs.to_string()));
  }

  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}