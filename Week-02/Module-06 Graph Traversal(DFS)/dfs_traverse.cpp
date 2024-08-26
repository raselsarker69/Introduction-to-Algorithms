#include <bits/stdc++.h>
using namespace std;

void init_code()
{
}
const int N = 1e5 + 5;
vector<int> adj_list[1000];
bool visited[N];

void dfs(int u)
{
    visited [u]==true;
    cout<<"Visited node" <<u<<endl;

    for (int v : adj_list[u])
    {  
        if(visited[v]==true) continue;
        dfs(v);      
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
        adj_list[u].push_back(v); 
        adj_list[v].push_back(u); 
    }

    for (int i = 1; i < n; i++)
    {
        cout << " Node " << i << " : " << " ";
             
        for (int j=0;j<adj_list[i].size();j++)
        {
            cout << adj_list[i][j] << " ";
        }
        cout << endl;
    }

    dfs(1);

    return 0;
}