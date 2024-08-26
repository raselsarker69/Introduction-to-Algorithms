#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5;
int parent[N];
int parentSize[N];

void dsu_set(int n)
{
    for(int i=1;i<=n;i++)
    {
        parent[i]=-1;
        parentSize[i]=1;
    }
}

void Find(int node)
{
    while(parent[node]!=-1)
    {
        node=parent[node];
    }
    return node;
}

void union_by_size(int a,int b)
{
    int leaderA=Find(a);
    int leaderB=Find(b);
    if(leaderA!=leaderB)
    {
        if(parent[leaderA]!=parent[leaderB])
        {
            parent[leaderB]=leaderA;
            parent[leaderA]+=parent[leaderB];
        }
        else
        {
            parent[leaderA]=leaderB;
            parent[leaderB]+=parent[leaderA];
        }
    }
}
int main()
{
    int n,e;
    cin>>n>>e;
    
    while(e--)
    {
        int a,b;
        cin>>a>>b;

    }
    return 0;
}