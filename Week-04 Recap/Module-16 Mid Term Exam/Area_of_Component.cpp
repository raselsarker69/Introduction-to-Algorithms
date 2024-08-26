#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int N = 1e3 + 5;
char g[N][N];
bool visited[N][N];
vector<pii> path = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int si, sj;
int n, m;

bool isValid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m && g[i][j] == '.');
}

int cnt;
void dfs(int si, int sj)
{
    visited[si][sj] = true;
    cnt++;
    for (int i = 0; i < 4; i++)
    {
        int ci = si + path[i].first;
        int cj = sj + path[i].second;
        if (isValid(ci, cj) && !visited[ci][cj])
        {
            dfs(ci, cj);
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

    //cin >> si >> sj;
    int minArea = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (isValid(i, j) && !visited[i][j])
            {
                cnt = 1;
                dfs(i, j);
                minArea = min(minArea, cnt);
            }
        }
    }

    if (minArea != INT_MAX)
    {
        cout << minArea-1 << " ";
    }
    else
    {
        cout << "-1"
             << " ";
    }

    return 0;
}