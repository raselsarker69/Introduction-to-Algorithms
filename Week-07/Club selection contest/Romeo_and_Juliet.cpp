#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
bool vis[N];
vector<int> v[N];
bool visited[105];

void dfs(int u, int k, int target, bool& canReunite) {
    if (k < 0) return; // Out of steps

    visited[u] = true;
    if (u == target && k >= 0) {
        canReunite = true;
        return;
    }

    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v, k - 1, target, canReunite);
        }
    }
}
void dfs(int s)
{
    vis[s] = true;
    cout << s << endl;
    for (int i = 0; i < v[s].size(); i++)
    {
        int child = v[s][i];
        if (vis[child] == false)
        {
            dfs(child);
        }
    }
}
int main() 
{
    int n,e;
    cin>>n>>e;
    for(int i=0;i<e;i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int x,y,k;
    cin>>x>>y>>k;

    bool flag = false;
    memset(visited, false, sizeof(visited));
    dfs(X, K, Y, flag);

    if (flag) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}