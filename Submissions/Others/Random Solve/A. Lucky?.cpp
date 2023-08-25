#include <bits/stdc++.h>
using namespace std;

int atoi(char c) {
  return c - '0';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while(t--) {
    string s; cin >> s;
    if(atoi(s[0]) + atoi(s[1]) + atoi(s[2]) ==  atoi(s[3]) + atoi(s[4]) + atoi(s[5])) {
      cout << "YES\n";
    }
    else {
      cout << "NO\n";
    }
  }

  return 0;
}