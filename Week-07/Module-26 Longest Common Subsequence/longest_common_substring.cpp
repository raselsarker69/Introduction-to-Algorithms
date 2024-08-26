#include<bits/stdc++.h>
using namespace std;
int main()
{
    string a,b; cin>>a>>b;
    int n=a.size(),m=b.size();
    int dp[n+1][m+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            dp[i][j]=0;
        }
    }
    return 0;
}