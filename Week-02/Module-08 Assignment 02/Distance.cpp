#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj[N];
bool mark[N];
int level[N];

bool bfs(int src)
{
    queue<int> q;
    q.push(src);

    mark[src] = true;
    level[src] = 0;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : adj[u])
        {
            if (mark[v] == true)
                continue;
            q.push(v);
            level[v] = level[u] + 1;
            mark[v] = true;
        }
    }
    return true;
}

int main()
{
    int n, m;
    cin >> n >> m;
    int k = m;
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int q;
    cin >> q;
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        if (a == b)
        {
            cout << "0\n";
            continue;
        }

        bfs(a);

        if (level[b] == 0)
            cout << "-1\n";
        else
            cout << level[b] << "\n";

        
        for (int i = 0; i <= 100000; i++)
        {
            level[i] = 0;
            mark[i] = false;
        }
    }

    return 0;
}