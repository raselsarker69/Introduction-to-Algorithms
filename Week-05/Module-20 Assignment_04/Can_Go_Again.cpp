#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll INF = 1e18;

class Edge
{
public:
    ll int u, v, w;
    Edge(ll int u, ll int v, ll int w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

int main()
{
    int n, e;
    cin >> n >> e;

    vector<Edge> v;
    while (e--)
    {
        ll int a, b, w;
        cin >> a >> b >> w;
        Edge ed(a, b, w);
        v.push_back(ed);
    }

    int s;
    cin >> s;
    ll int dis[n + 1];
    for (int i = 1; i <= n; i++)
    {
        dis[i] = INF;
    }

    dis[s] = 0;
    for (int i = 1; i <= n - 1; i++)
    {
        for (int j = 0; j < v.size(); j++)
        {
            Edge ed = v[j];
            int a = ed.u;
            int b = ed.v;
            int w = ed.w;
            if (dis[a] != INF && dis[a] + w < dis[b])
            {
                dis[b] = dis[a] + w;
            }
        }
    }

    int t;
    cin >> t;

    while(t--)
    {
        int d;
        cin>>d;
        bool isCycle = false;
        for (int j = 0; j < v.size(); j++)
        {
            Edge ed = v[j];
            int a = ed.u;
            int b = ed.v;
            int w = ed.w;
            if (dis[a] != INF && dis[a] + w < dis[b])
            {
                isCycle = true;
                break;
            }
        }
        if (isCycle)
        {
            cout << "Negative Cycle Detected" << endl;
            return 0;
        }
        else if (dis[d] == INF)
        {
            cout << "Not Possible" << endl;
        }
        else
        {
            cout << dis[d] << endl;
        }
    }

    return 0;
}