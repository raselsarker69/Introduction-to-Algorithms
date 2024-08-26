#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int N = 1e3 + 10;
vector<string> graph;
int visited[N][N];
int level[N][N];                                                     
pii parent[N][N];
int n, m;
vector<pii> derec = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

bool isValid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}
void dfs(int si, int sj)
{
    queue<pii> q;
    q.push({si, sj});
    visited[si][sj] = true;
    level[si][sj] = 0;

    while (!q.empty())
    {
        pii upair = q.front();
        int i = upair.first;
        int j = upair.second;
        q.pop(); 

        for (pii d : derec) 
        {
            int ni = i + d.first;
            int nj = j + d.second;

            if (isValid(ni, nj) && !visited[ni][nj] && graph[ni][nj] != '#')
            {
                q.push({ni, nj});
                visited[ni][nj] = true;
                level[ni][nj] = level[i][j] + 1;
                parent[ni][nj] = {i, j};
            }
        }
    }
}
int main()
{
    int si, sj, di, dj;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string x;
        cin >> x;
        for (int j = 0; j < m; j++)
        {
            if (x[j] == 'A')  
            si = i, sj = j;

            if (x[j] == 'B')  
            di = i, dj = j;

        }
        graph.push_back(x);
    }


    dfs(si, sj);
    
    if(level[di][dj]!=0)
    {
        cout<<"YES\n";
        cout<<level[di][dj]<<endl;
    }
    else 
       cout<<"NO\n";

    //---------------------------------------------------//
    
    vector<pii> path;
    pii curr={di,dj};

    while(!(curr.first==si && curr.second==sj))
    {
        path.push_back(curr);
        curr=parent[curr.first][curr.second];
    }

    for(int i=0;i<path.size();i++)
    {
        if(path[i-1].first==path[i].first)
        {
            if(path[i-1].second==path[i].second-1)
            {
                cout<<"R\n";
            }
            else cout<<"L\n";
        }
        else
        {
            if(path[i-1].first==path[i].first-1)
            {
                cout<<"D\n";
            }
            else cout<<"U\n";
        }
    }
    return 0;
}