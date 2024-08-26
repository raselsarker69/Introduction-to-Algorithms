#include <bits/stdc++.h>
using namespace std;

const int N = 1e3+5; 
vector<int> adj[N];
bool visited[N];
int cnt = 0; 
void dfs(int u)
{
    visited[u] = true;
    
    for (int v : adj[u])
    {
        if (!visited[v])
        {  
            cnt++;
            dfs(v); 
        }   
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
 
    }

    int k = 0;
    cin >> k;
    
    dfs(k); 
    cout << cnt << " ";

    return 0;
}