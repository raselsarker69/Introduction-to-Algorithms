#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
const int N=1e5+5;
const int INF=1e9+10;

vector<pii> adj[N];
vector<int> dist(N,INF);
vector<bool> visited(N);

void dijkstra(int src)
{
    priority_queue<pii,vector<pii>,greater<pii> > pq;
    dist[src]=0;
    pq.push({dist[src],src});

    while(!pq.empty())
    {
        int u=pq.top().second;
        pq.pop();
        visited[u]=true;

        for(pii vpair:adj[u])
        {
            int v=vpair.first;
            int w=vpair.second;

            if(visited[v]) continue;
            if(dist[v]>dist[u]+w)
            {
                dist[v]=dist[u]+w;
                pq.push({dist[v],v});
            }
        }
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int a,b,w;
        cin>>a>>b>>w;
        adj[a].push_back({b,w}); 
    }

    int s,e;
    cin>>s>>e;
    dijkstra(s);

    cout<<dist[e]<<endl;
    return 0;
}