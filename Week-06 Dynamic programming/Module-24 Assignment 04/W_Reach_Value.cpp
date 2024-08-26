#include <bits/stdc++.h>
#define ll long long
using namespace std;
int chack(ll n, ll x)
{
    if (n == x)
        return true;
    if (n > x)
        return false;
    return chack(n * 10, x) || chack(n * 20, x);
}
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        if (chack(1, n))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}