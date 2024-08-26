#include <bits/stdc++.h>
using namespace std;

void init_code()
{
}
const int N = 1e3 + 5;
bool visited[N];
vector<int> adj[N];
int level[N];

bool bfs(int src)
{
    queue<int> q;
    q.push(src);

    visited[src] = true;
    level[src] = 0;

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
            level[v] = level[u] + 1;
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

    bfs(1);

    //int k; cin>>k;
    for (int i = 1; i <= n; i++)
    {
        cout << "Level of " << i << ":" << level[i] << endl;
    }
    return 0;
}