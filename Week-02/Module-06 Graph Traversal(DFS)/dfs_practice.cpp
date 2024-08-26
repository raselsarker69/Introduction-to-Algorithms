#include <bits/stdc++.h>
using namespace std;

void init_code()
{
}
const int N = 1e3 + 5;
vector<int> adj[N];
bool visited[N];

void dfs(int par)
{
    cout << par << " ";
    visited[par] = true;

    for (int child : adj[par])
    {
        if (visited[child] == 0)
        {
            dfs(child);
        }
    }
}
int main()
{
    int n, m;
    cin >> m >> n;
    for (int i = 0; i < m; i++)
    {

        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i < n; i++)
    {
        cout << "Node of " << i << ":";
        for (int j = 0; j < adj[i].size(); j++)
        {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}