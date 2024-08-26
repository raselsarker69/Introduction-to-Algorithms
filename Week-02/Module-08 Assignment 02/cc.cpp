#include <bits/stdc++.h>
using namespace std;

const int N = 1e3+5;
vector<int> adj[N];

int main()
{
    int n, e;
    cin >> n >> e;
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int k; 
    cin >> k;
    //int cc=0;
    for (int i = 0; i < n; i++)
    {
        //cc++;
        cout<<k<<" ";
        
    }
    
    return 0;
}