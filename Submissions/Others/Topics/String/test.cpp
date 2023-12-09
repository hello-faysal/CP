#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cout << "here update\n";
  vector<int> v;
  v.push_back(5);
  map<int, int> mp;
  mp[5] = 1;
  for (auto [x, y] : mp) {
    cout << x << ' ' << y << '\n';
  }

  return 0;
}