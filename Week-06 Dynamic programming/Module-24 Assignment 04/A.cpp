#include <bits/stdc++.h>
using namespace std;

int dp[1005][1005];

int knapsack(int n, int s, int v[], int w[]) 
{
    for (int i = 0; i <= n; i++) 
    {
        for (int j = 0; j <= s; j++) 
        {
            if (i == 0 || j == 0) 
            {
                dp[i][j] = 0;
            } 
            else 
            {
                if (w[i - 1] <= j) 
                {
                    dp[i][j] = max(dp[i - 1][j - w[i - 1]] + v[i - 1], dp[i - 1][j]);
                } 
                else 
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
    }
    return dp[n][s];
}

int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        int n, s;
        cin >> n >> s;
        int v[n], w[n];
        for (int i = 0; i < n; i++) 
        {
            cin >> w[i] >> v[i];
        }

        int ans = knapsack(n, s, v, w);
        cout << ans << endl;
    }
    return 0;
}
