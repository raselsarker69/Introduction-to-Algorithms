#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5;
int dis[N];
int par[N];
bool vis[N];
vector<int> v[N];

void bfs(int s)
{
    queue<int> q;
    q.push(s);
    dis[s]=0;
    par[s]=-1;
    vis[s]=true;

    while(!q.empty())
    {
        for(int child:v[parent])
        {
            if(!vis[child])
            {
                int parent=q.front();
                q.pop();
                dis[child]=dis[parent]+1;
                par[child]=parent;
                vis[child]=true;
            }
        }
    }

}

int main()
{
    int n,e;
    cin>>n>>e;
    for(int i=0;i<e;i++)
    {
        int a,b; 
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    bfs(1);

    int dis; cin>>dis;
    for(int i=0;i<n;i++)
    {
        vector<int> path;
        path.push_back(dis);

    }
    return 0;
}