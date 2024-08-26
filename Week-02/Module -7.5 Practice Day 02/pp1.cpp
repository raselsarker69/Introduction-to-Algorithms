#include <bits/stdc++.h>
using namespace std;

void init_code()
{
}
const int N = 1e5 + 5;
vector<int> adj[N];
bool visited[N];
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
            bfs(v);
        }
        cout << u << " ";
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

    bfs(1);
    return 0;
}