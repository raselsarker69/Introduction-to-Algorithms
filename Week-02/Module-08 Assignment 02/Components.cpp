#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
vector<int> adj[N];
bool visited[N];

int cnt=0;

void dfs(int par)
{
    cnt++;
    visited[par]=true;
    for(int child:adj[par])
    {
        if(visited[child]==0)
        {
           dfs(child);
        }
    }  
}

int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> result;
    for (int i = 1; i < N; i++)
    { 
        if (visited[i]) continue;
        cnt=0;
        dfs(i);
        if(cnt>1)
        result.push_back(cnt);    
    }
    
    sort(result.begin(), result.end());

    for (auto size : result)
    {    
        cout << size << " ";
    }

    return 0;
}