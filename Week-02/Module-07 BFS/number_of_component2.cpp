#include <bits/stdc++.h>
using namespace std;
 
const int N = 1e5 + 5;
vector<int> adj[N];
int visited[N];
vector<int> v[N];
int row = 0;

void dfs(int u)
{
    visited[u] = true;
    v[row].push_back(u);
    for (int v : adj[u])
    {
        if (visited[v]) continue;    
        dfs(v);
    }
}

int main()
{
 
    int n, m;
    cin >> n >> m;
 
    for (int i = 0; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
 
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
 
    int cc = 0;
 
    for (int i = 1; i <= n; i++)
    {
        if (visited[i])
            continue;
        dfs(i);
        cc++;
        row++;
    }
    cout << cc <<endl;
    for (int i = 0; i < row; i++)
    {
        cout << "component " << i + 1 << ": ";
        for (int j : v[i])
        {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}