#include <bits/stdc++.h>
using namespace std;

void init_code()
{
}

const int N = 1e3 + 5;
vector<int> adj[N];
bool visited[N];
int level[N];
int parent[N];

void bfs(int src)
{
    queue<int> q;
    q.push(src);

    visited[src] = true;
    level[src] = 0;
    parent[src] = -1;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v : adj[u])
        {
            if (visited[v])
                continue;
            q.push(v);
            visited[v] = true;
            level[v] = level[u] + 1;
            parent[v] = u;
        }
    }
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

    int src, dst;
    cin >> src >> dst;

    bfs(src);

    cout << "Distance : " << level[dst] << endl;

    // for (int i = 1; i <= n; i++)
    // {
    //     cout << "parent of " << i << " : " << parent[i] << endl;
    // }

    vector<int> path;
    int cur = dst;
    while (cur != -1)
    {
        path.push_back(cur);
        cur = parent[cur];
    }

    reverse(path.begin(), path.end());
    cout << "path : ";

    for (int node : path)
    {
        cout << node << " ";
    }

    return 0;
}