#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll fact(ll n)
{
    if (n == 0)
        return 1;
    
    ll ans = fact(n - 1);
    return ans * n;
    
}

int main()
{
    ll n;
    cin >> n;
    ll ans = fact(n);
    cout << ans << endl;
    return 0;
}