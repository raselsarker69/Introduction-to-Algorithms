#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n; cin>>n;
    int v[n],w[n];
    for(int i=0;i<n;i++)
    {
        cin>>v[i]>>w[i];
    }

    int s; cin>>s;
    int dp[n+1][s+1];

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=s;j++)
        {
            dp[i][j]=0;
        }
    }

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=s;j++)
        {
            if(w[i-1]<=j)
            {
                dp[i][j]=max(v[i-1]+dp[i-1][j-w[i-1]],dp[i-1][j]);
            }
            else
            {
                dp[i][j]=dp[i-1][j];
            }
        }
    }

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=s;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
