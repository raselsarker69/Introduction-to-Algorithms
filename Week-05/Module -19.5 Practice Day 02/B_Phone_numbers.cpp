#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int nm, div = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> nm;
        div = nm / 3;
    }
    cout << div << endl;
    return 0;
}
/*https://ideone.com/IH6Dxb*/