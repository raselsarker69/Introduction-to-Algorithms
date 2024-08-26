#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int N = 1e3 + 5;
char g[N][N];
bool visited[N][N];
vector<pii> path = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int si, sj, di, dj;
int n, m;

bool isValid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m && g[i][j] == '.');
}

int cnt = 0;
void bfs(int si, int sj)
{
    queue<pii> q;
    q.push({si, sj});
    visited[si][sj] = true;
    cnt++;

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
                cnt++;
                visited[ci][cj] = true;
                g[ci][cj] = '.';
            }
        }
    }
}

int main() 
{
    cin >> n >> m;
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            cin >> g[i][j];
        }
    }
    
    cin >> si >> sj >> di >> dj;
    bfs(si, sj);

    if (visited[di][dj]) 
    {
        cout << "YES" << endl;
    } 
    else 
    {
        cout << "NO" << endl;
    }

    return 0;
}