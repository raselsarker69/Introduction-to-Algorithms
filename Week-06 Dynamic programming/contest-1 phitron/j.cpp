#include<bits/stdc++.h>
using namespace std;

int main() 
{
    int n, s, k; 
    cin >> n;
    s = n - 1;
    k = 1;
    for (int i = 1; i <= n; i += 2) 
    {
        s = (n - i) / 2; 
        for (int j = 0; j < s; j++) {
            cout << " ";
        }
        for (int j = 0; j <= k; j++) {
            cout << "*";
        }
        cout << endl;
    }

    s = (n - 3) / 2;
    for (int i = 0; i < s; i++) {
        cout << " ";
    }
    cout << "***" << endl;

    return 0;
}