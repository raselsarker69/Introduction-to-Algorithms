#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj[N];
bool visited[N];
int depth[N];
int height[N];

void dfs(int u)
{
    visited[u] = true;
    for (int v : adj[u])
    {
        if (visited[v]==true) continue;
        depth[v] = depth[u] + 1;
        dfs(v);
          
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v); 
    }
    int k; cin>>k;
    dfs(1);
    cout << "Depth of " << k << " = " << depth[k] << endl;
    
    return 0;
}