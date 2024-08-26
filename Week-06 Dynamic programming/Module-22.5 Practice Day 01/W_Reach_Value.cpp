#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool reachValue(ll num, ll x) 
{  
    if (x < num) 
    {
        return false;
    }
    if (x == num) 
    {
        return true;
    }
    return reachValue(num * 10, x) || reachValue(num * 20, x);
}

int main() 
{
    ll t;
    cin >> t;

    while (t--) 
    {
        ll n;
        cin >> n;
        if (reachValue(1, n)) 
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