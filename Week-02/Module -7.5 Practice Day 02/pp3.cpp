#include <bits/stdc++.h>
using namespace std;

void init_code()
{
}
const int N = 1e3 + 5;
vector<int> adj[N];
bool visited[N];

bool dfs(int u, int p = -1)
{
    bool cycleExists = false;
    visited[u] = true;
    for (int v : adj[u])
    {
        if (v == p) continue;    
        if (visited[v]) return true;    
        cycleExists = cycleExists || dfs(v, u);

    }
    return cycleExists;
}

int main()
{
    init_code();
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }


    bool iscycle=false;
    for(int i=1;i<=n;i++)
    {
        if(visited[i]) continue;
        iscycle |=dfs(i);
    }

    if (iscycle)
        cout << "YES\n";
    
    else
        cout << "NO\n";

    return 0;
}