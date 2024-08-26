#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj[N];

int main()
{
    int n;
    cin >> n;
    int adjmat[n + 2][n + 2];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> adjmat[i][j];
        }
    }

    vector<int> adj[n + 2];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (adjmat[i][j] == 1)
            {
                adj[i].push_back(j);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << "List " << i << " : ";
        for (int j = 0; j < adj[i].size(); j++)
        {
            cout << adj[i][j] << " ";
        }
        cout << endl; 
    }
    return 0;
}