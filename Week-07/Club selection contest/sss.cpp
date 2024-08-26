#include <bits/stdc++.h>
using namespace std;

int main()
{
    string w1, w2;
    cin >> w1 >> w2;
    int n = w1.size();
    int m = w2.size();
    int dp[n + 1][m + 1];

    // for (int i = 0; i <= n; i++)
    // {
    //     for (int j = 0; j <= m; j++)
    //     {
    //         if (i == 0 || j == 0)
    //             dp[i][j] = 0;
    //     }
    // }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (w1[i - 1] == w2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    if (dp[n][m] == w2.size())
    {
        cout << "Possible" << endl;
    }
    else
    {
        cout << "Impossible" << endl;
    }

    return 0;
}