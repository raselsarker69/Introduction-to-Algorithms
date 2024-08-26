#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cout << i;
    }
    cout << endl;

    for (int i = 2; i < n; i++)
    {
        for (int j = 2; j < n; j++)
        {
            cout << "";
        }
        cout << i;
        for (int j = i + 1; j < n; j++)
        {
            cout << "  ";
        }
        cout << n << endl;
    }

    for (int i = 2; i <= n; i++)
    {
        cout << n;
    }
    cout << endl;

    return 0;
}