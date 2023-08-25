#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;
const double PI = double(2 * acos(0.0));

void solve() {
    long long n, k; cin >> n >> k;
    if((n & 1) == 0) {
        cout << "YES\n";
        return;
    }
    if(((n - k) & 1) == 0) {
        cout << "YES\n";
        return;
    }

    cout << "NO\n";
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