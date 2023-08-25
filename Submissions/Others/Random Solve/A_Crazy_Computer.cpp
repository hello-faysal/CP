#include <bits/stdc++.h>
using namespace std;

#define pb(v) push_back(v)
#define ll long long
#define mod 1000000007
#define PI double(2 * acos(0.0))

void solve()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n, c, i, a, b, ans;
    cin >> n >> c;

    int arr[n];
    for (i = 0; i < n; i++)
        cin >> arr[i];

    ans = 1;

    for (i = 1; i < n; i++)
    {
        b = arr[i];
        a = arr[i - 1];

        if ((b - a) > c)
            ans = 1;
        else
            ans++;
    }

    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll test = 1;
    // cin>>test;
    while (test--)
    {
        solve();
    }
    return 0;
}
