#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll a, b;
        cin >> a >> b;
        int lastdigita = a % 100;
        int lastdigitb = b % 100;
        int mult = (lastdigita * lastdigitb) % 100;

        cout << mult << endl;
            
    }
    return 0;
}