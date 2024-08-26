#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> ad[N];
bool visited[N];
int level[N];

void bfs(int u)
{
    queue<int> q;
    q.push(u);
    visited[u] = true;
    level[u] = 0;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v : ad[u])
        {
            if (visited[v] == true)
                continue;
            q.push(v);
            visited[v] = true;
            level[v] = level[u] + 1;
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
        ad[a].push_back(b);
        ad[b].push_back(a);
    }
    
    int l; 
    cin>>l;
    if(l==0)
    {
        cout<<0<<" ";
        return 0;
    }
    bfs(0);
    int flag=0;
    for(int i=0;i<N;i++)
    {
        if(level[i]==l)
        {
            cout<<i<<" ";
            flag=1;;
        }
    }

    if(flag==0) 
    cout<<"-1"<<endl;
    
    return 0;
}