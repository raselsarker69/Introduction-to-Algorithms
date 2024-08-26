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
    bool iscycleExist = false;
    visited[u] = true;
    for (int v : adj[u])
    {
        if (v == p)
            continue;
        if (visited[v])
            return true;
        iscycleExist = iscycleExist || dfs(v, u);
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
        adj[v].push_back(u);
    }
    bool iscycle = false;
    for (int i = 1; i <= n; i++)
    {
        if (visited[i])
            continue;
        iscycle |= dfs(i);
    }

    if (iscycle)
        cout << "cycle detected!\n";
    else
        cout << "not cycle detected!\n";
    return 0;
}