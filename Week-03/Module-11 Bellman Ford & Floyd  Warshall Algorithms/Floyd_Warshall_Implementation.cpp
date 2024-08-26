#include<bits/stdc++.h>
using namespace std;
/*
5 7
1 2 2
1 3 6
2 3 1
3 4 4
4 2 6
2 5 3
5 4 9
*/

void init_code()
{
}

typedef pair<int,int> pii;
const int N=1e3+5;
const int INF=1e9+10;

int d[N][N];
int n,m;

void print_matrix()
{
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(d[i][j]==INF) cout<<"X"<<" ";
            else 
                cout<<d[i][j]<<" ";
        }
        cout<<endl;
    }
}

void dist_initialize()
{
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i!=j)
            d[i][j]=INF;
        }
    }
}

int main()
{
    init_code();
    cin>>n>>m;
    dist_initialize();

    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        d[u][v]=w;
        //d[v][u]=w;
    }

    print_matrix();

    for(int k=0;k<=n;k++)
    {
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=n;j++)
            {
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
            }
        }
    }
    cout<<"\nAfter floyd Warshall:\n";
    print_matrix();

    return 0;
}