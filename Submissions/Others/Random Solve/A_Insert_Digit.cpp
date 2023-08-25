#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;
const double PI = double(2 * acos(0.0));

void solve() {
    int n; cin >> n;
    char c; cin >> c;
    string s; cin >> s;
    int flag = 0;
    for(auto i : s) {
        if(!flag && c > i) {
            cout << c;
            flag = 1;
        }
        cout << i;
    }
    if(!flag) {
        cout << c;
    }
    cout << '\n';
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