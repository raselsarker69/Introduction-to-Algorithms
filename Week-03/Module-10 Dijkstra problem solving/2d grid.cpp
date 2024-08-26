#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int N = 1e3 + 4;
vector<string> graph; // Store the grid as strings
int visited[N][N];
int level[N][N];
pii parent[N][N];
vector<pii> derec = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
int n, m;
int si, sj, di, dj; // Variables to store starting and destination positions

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
        q.pop(); // Don't forget to pop the front element

        for (pii d : derec)
        {
            int ni = i + d.first;
            int nj = j + d.second;

            if (isValid(ni, nj) && !visited[ni][nj] && graph[ni][nj] != '#')
            {
                visited[ni][nj] = true;
                level[ni][nj] = level[i][j] + 1;
                parent[ni][nj] = {i, j};
                q.push({ni, nj}); // Push the new position to the queue
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++) // Iterate over rows
    {
        string x;
        cin >> x;
        graph.push_back(x);

        for (int j = 0; j < m; j++) // Iterate over columns
        {
            if (x[j] == 'A')
            {
                si = i;
                sj = j;
            }
            if (x[j] == 'B')
            {
                di = i;
                dj = j;
            }
        }
    }
    dfs(si, sj);

    if (level[di][dj] != 0)
    {
        cout << "YES" << endl;
        cout << level[di][dj] << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}