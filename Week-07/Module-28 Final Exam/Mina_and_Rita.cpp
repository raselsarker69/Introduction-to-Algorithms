#include <bits/stdc++.h>
using namespace std;
int dp[1005][1005];

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string st1, st2;
        cin >> st1 >> st2;
        int n = st1.size();
        int m = st2.size();

        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                if (i == 0 || j == 0)
                    dp[i][j] = 0;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (st1[i - 1] == st2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        int insert = n + m - dp[n][m];
        cout << insert << endl;
    }
    return 0;
}