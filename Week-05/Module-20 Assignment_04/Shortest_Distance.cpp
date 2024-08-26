#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
const long long int INF = 1e18;
long long int dis[N][N];
int main()
{
    int n, e;
    cin >> n >> e;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j) 
               dis[i][j] = 0;

            else 
               dis[i][j] = INF;
        }
    }
    while (e--)
    {
        long long int a, b, w;
        cin >> a >> b >> w;
        dis[a][b] = min(dis[a][b],w);
    }

    

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (dis[i][k] + dis[k][j] < dis[i][j])
                {
                    dis[i][j] = dis[i][k] + dis[k][j];
                }
            }
        }
    }

    int q;
    cin >> q;
    while (q--)
    {
        long long int u, v;
        cin >> u >> v;
        if (dis[u][v] == INF)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << dis[u][v] << endl;
        }
    }
    return 0;
}