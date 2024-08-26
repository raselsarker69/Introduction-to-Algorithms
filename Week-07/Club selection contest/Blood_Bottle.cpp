#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;

        int zazaDrank = 0;
        int n = s.length();

        for (int i = 0; i < n; i++)
        {
            char current = s[i];
            int j = i + 1;

            while (j < n && s[j] == current)
            {
                j++;
            }

            int bottleDrank = j - i;
            zazaDrank += (current == '1') ? bottleDrank : 0;

            i = j - 1;
        }
        cout << zazaDrank << endl;
    }
    return 0;
}