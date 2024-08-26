#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll n;
    cin >> n;
    ll line = (n + 1) / 2 + 5;
    ll sp = line - 1;
    ll st = 1;
    for (ll i = 1; i <= line; i++)
    {
        for (ll j = 1; j <= sp; j++)
            cout << " ";
        for (ll j = 1; j <= st; j++)
            cout << "*";
        sp--;
        st += 2;
        cout << endl;
    }
    ll start = ((line * 2) - 1 - n) / 2;
    for (ll i = 1; i <= 5; i++)
    {
        for (ll j = 1; j <= start; j++)
            cout << " ";
        for (ll j = 1; j <= n; j++)
            cout << "*";
        cout << endl;
    }
    return 0;
}