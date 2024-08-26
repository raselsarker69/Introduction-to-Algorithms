#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int N = 1e3 + 10;
vector<string> graph;
int visited[N][N];
int level[N][N];
int n, m;
vector<pii> derec = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {-2, 1}, {2, -1}, {-2, -1}};

bool isValid(int i, int j)
{
    return (i >= 0 && i < 8 && j >= 0 && j < 8);
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

            if (isValid(ni, nj) && !visited[ni][nj] )
            {
                q.push({ni, nj});
                visited[ni][nj] = true;
                level[ni][nj] = level[i][j] + 1;
               
            }
        }
    }
}

void reset_level_vic()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            level[i][j] = 0;
            visited[i][j] = false;
        }
    }
}
int main()
{
    int n;
    cin >> n; // Read the number of test cases
    for (int i = 0; i < n; i++)
    {
        string x, y;
        cin >> x >> y;
        int si, sj, di, dj;

        si = x[0] - 'a'; // Assign row value to si
        sj = x[1] - '1'; // Assign column value to sj

        di = y[0] - 'a'; // Assign row value to di
        dj = y[1] - '1';

        // cout << "(" << si << "," << sj << ") ";
        // cout << "(" << di << "," << dj << ")\n";

        dfs(si, sj);
        cout << level[di][dj] << endl;
        reset_level_vic();
    }
    return 0;
}