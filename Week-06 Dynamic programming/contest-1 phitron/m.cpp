#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n; 
    cin>>n;
    long long int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    long long int t; 
    cin>>t;
    while(t--)
    {
        long long int x,y,z;
        cin>>x>>y>>z;
        for(int i=x;i<=y;i++)
        {
            a[i]+=z;
        }
    }
    
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}
