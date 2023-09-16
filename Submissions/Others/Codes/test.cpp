#include <bits/stdc++.h>
using namespace std;

// @author: faysalahammedchowdhury

const int N = 1e5 + 9;
pair<int, int> Q[N];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, q; cin >> n >> q;
  for(int i = 1; i <= n; i++) {
    cin >> Q[i].first >> Q[i].second;
  }

  int mx;
  if(Q[n].first == 1) {
    mx = Q[n].second;
  }
  else if(Q[n].first == 2) {
    mx = (1 << 30) - 1;
  }
  else if(Q[n].first == 3) {
    mx = 0;
    int len = __lg(Q[n].second);
    for(int k = 0; k <= len; k++) {
      if((Q[n].second & (1 << k)) == 0) {
        mx += 1 << k;
      }
    }
  }
  for(int i = n - 1; i >= 1; i--) {
    int mx_tmp = mx;
    if(Q[i].first == 2) {
      mx = 0;
      for(int k = 0; k < 30; k++) {
        if((mx_tmp & (1 << k))) {
          if(Q[i].second & (1 << k)) {
          }
          else {
            mx += (1 << k);
          }
        }
      }
    }
    else if(Q[i].first == 1) {
      mx = 0;
      for(int k = 0; k < 30; k++) {
        if((mx_tmp & (1 << k)) && (Q[i].second & (1 << k))) {
          mx += (1 << k);
        }
      }
    }
    else {
      mx = 0;
      for(int k = 0; k < 30; k++) {
        if((mx_tmp & (1 << k)) && (Q[i].second & (1 << k)) == 0) {
          mx += (1 << k);
        }
      }
    }
  }

  for(int i = 1; i <= q; i++) {
    int x; cin >> x;
    if(mx <= x) {
      cout << mx << '\n';
    }
    else {
      int tmp = mx;
      for(int k = 0; k < 30; k++) {
        if((x & (1 << k)) == 0 && (mx & (1 << k))) {
          tmp -= (1 << k);
        }
      }
      cout << tmp << '\n';
    }
  }

  return 0;
}