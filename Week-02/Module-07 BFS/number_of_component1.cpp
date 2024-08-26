#include <bits/stdc++.h>
using namespace std;

void init_code()
{
}
const int N = 1e3 + 5;
vector<int> adj[N];
bool visited[N];

void dfs(int u)
{
    visited[u] = true;
    for (int v : adj[u])
    {
        if (visited[v])
            continue;
        dfs(v);
    }
}
void bfs(int src)
{
    queue<int> q;
    q.push(src);
    visited[src] = true;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : adj[u])
        {
            if (visited[v] == true)
                continue;
            q.push(v);
            visited[v] = true;
        }
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

    int cc = 0;
    for (int i = 1; i <= n; i++)
    {
        //cout << "Component " << i << " : " << endl;      
        if (visited[i])
            continue;
        bfs(i);
        cc++;
    }

    cout << "component: " << cc << endl;

    return 0;
}