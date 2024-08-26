#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    ll a[n];
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ll dp[n + 1];
    dp[0] = 0;
    dp[1] = max(a[0], 0LL);
    for (ll i = 2; i <= n; i++)
    {
        if (a[i - 1] == -1)
            dp[i] = dp[i - 1];
        else
            dp[i] = max(dp[i - 2] + a[i - 1], dp[i - 1]);
    }
    cout << dp[n] << endl;
    return 0;
}