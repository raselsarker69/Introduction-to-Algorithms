#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
const int N=1e3+5;
const int INF=1e9+6;
vector<pair<pii,int>> list_of_edge;
vector<pii> adj[N];
int dist[N];
int n,m;

void bellman_ford(int src)
{
    for(int i=1;i<=n;i++)
    dist[i]=INF;
    dist[src]=0;

    for(int i=0;i<n;i++)
    {
        for(int u=1;u<n;u++)
        {
            for(pii vpair:adj[u])
            {
                int v=vpair.first;
                int w=vpair.second;

                if(dist[u]!=INF && dist[v]>dist[u]+w)
                dist[v]=dist[u]+w;
            }
        }
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    while(m--)
    {
        int u,v,w;
        cin>>u>>v>>w;
        list_of_edge.push_back({{u,v},w});
    }

    bellman_ford(1);

    for(int i=1;i<=n;i++)
    {
        cout<<"distance of"<<i<<" "<<dist[i]<<endl;
    }
    return 0;
}