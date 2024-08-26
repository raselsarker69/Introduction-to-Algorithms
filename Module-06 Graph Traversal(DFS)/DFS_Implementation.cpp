#include <bits/stdc++.h>
using namespace std;

void init_code()
{
}
const int N = 1e5 + 5;
vector<int> adj[N];
bool visited[N];


void dfs(int u)
{
    //step 1: actions just after entering noden u
    visited [u]==true;
    cout<<"Visited node" <<u<<endl;

    for (int v : adj[u])
    {
        //step 2:actions before entering new neighbor  
        if(visited[v]==true) continue;
        dfs(v);
        //step 3: actions after existing a neighbor
    }
    //step 4:actions after existing node u
    
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
        adj[u].push_back(v); // directed and unweight
        // adj[v].push_back(u);  //undirected and unweight
    }

    /*for (int i = 1; i <= n; i++)
    {
        cout << " Node " << i << " : " << " ";
             
        for (int j : adj[i])
        {
            cout << j << " ";
        }
        cout << endl;
    }*/
    dfs(1);

    return 0;
}