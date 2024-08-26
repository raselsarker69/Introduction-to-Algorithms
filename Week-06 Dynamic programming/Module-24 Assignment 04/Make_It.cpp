#include <bits/stdc++.h>
using namespace std;
int dp[100005];

bool knapsack(int i, int n)
{
    if (i == n)
        return true;
    if (i > n)
        return false;

    if (dp[i] != -1)
    {
        return dp[i];
    }

    bool op1 = knapsack(i + 3, n);
    bool op2 = knapsack(i * 2, n);

    return dp[i] = op1 || op2;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        for (int i = 0; i <= n; i++)
        {
            dp[i] = -1;
        }

        if (knapsack(1, n))
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