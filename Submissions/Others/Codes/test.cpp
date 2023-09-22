#include <bits/stdc++.h>
using namespace std;

int main() {
  int t; cin >> t;
  for(int i = 0; i < t; i++) {
    string s; cin >> s;
    if(s == "bca" or s == "cab") {
      cout << "No\n";
    }
    else {
      cout << "Yes\n";
    }
  }

  return 0;
}