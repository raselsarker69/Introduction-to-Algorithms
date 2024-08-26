#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
const int N=1e3+5;
int dis[N][N];
bool visited[N][N];
int n,m;
vector<pii> path={{-2,1},{-2,-1},{2,1},{2,-1},{1,2},{1,-2},{-1,2},{-1,-2}};

bool isValid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m );
}

void bfs(int si, int sj)
{
    queue<pii> q;
    dis[si][sj] = 0;
    visited[si][sj] = true;
    q.push({si, sj});
    
    while (!q.empty())
    {
        pii f = q.front();
        q.pop();
        int pi = f.first;
        int pj = f.second;
        for (auto d : path)
        {
            int ci = pi + d.first;
            int cj = pj + d.second;
            if (isValid(ci, cj) && !visited[ci][cj])
            {
                q.push({ci, cj});
                visited[ci][cj] = true;
                dis[ci][cj] = dis[pi][pj] + 1;
            }
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int ki, kj, qi, qj;
        cin >> n >> m >> ki >> kj >> qi >> qj;
    
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                dis[i][j]=-1;
                visited[i][j]=false;
            }
        }
        bfs(ki, kj);
        cout << dis[qi][qj] << endl;
    }
    
    return 0;
}