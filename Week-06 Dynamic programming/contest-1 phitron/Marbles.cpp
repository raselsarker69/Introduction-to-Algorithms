#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll n;
    cin >> n;
    ll a[n], d[n + 1];
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    d[0] = a[0];
    for (ll i = 1; i < n; i++)
    {
        d[i] = a[i] - a[i - 1];
    }
    ll q;
    cin >> q;
    while (q--)
    {
        ll a, b, x;
        cin >> a >> b >> x;
        d[a] += x;
        d[b + 1] -= x;
    }
    a[0] = d[0];
    for (ll i = 1; i < n; i++)
    {
        a[i] = a[i - 1] + d[i];
    }
    for (ll i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}