#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 1e5 + 5;
ll par[N];
ll parentLevel[N];
ll parentSize[N];
void dsu_set(ll n)
{
    for (ll i = 0; i <= n; i++)
    {
        par[i] = -1;
        parentLevel[i] = 0;
        parentSize[i] = 1;
    }
}
ll dsu_find(ll n)
{
    if (par[n] == -1)
        return n;
    ll leader = dsu_find(par[n]);
    par[n] = leader;
    return leader;
}
void dsu_union(ll a, ll b)
{
    ll leaderA = dsu_find(a);
    ll leaderB = dsu_find(b);
    if (leaderA != leaderB)
    {
        if (parentLevel[leaderA] > parentLevel[leaderB])
        {
            par[leaderB] = leaderA;
        }
        else if (parentLevel[leaderB] > parentLevel[leaderA])
        {
            par[leaderA] = leaderB;
        }
        else
        {
            par[leaderB] = leaderA;
            parentLevel[leaderA]++;
        }
    }
}
class Edge
{
public:
    ll a, b, w;
    Edge(ll a, ll b, ll w)
    {
        this->a = a;
        this->b = b;
        this->w = w;
    }
};
bool cmp(Edge a, Edge b)
{
    return a.w < b.w;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, e;
    cin >> n >> e;
    vector<Edge> v;
    vector<Edge> ans;
    dsu_set(n);
    while (e--)
    {
        ll a, b, w;
        cin >> a >> b >> w;
        v.push_back(Edge(a, b, w));
    }
    sort(v.begin(), v.end(), cmp);
    ll cnt = 0, cost = 0;
    for (Edge val : v)
    {
        ll a = val.a;
        ll b = val.b;
        ll w = val.w;
        ll leaderA = dsu_find(a);
        ll leaderB = dsu_find(b);
        if (leaderA == leaderB)
        {
            cnt++;
            continue;
        }
        ans.push_back(val);
        cost += val.w;
        dsu_union(a, b);
    }
    bool hs = true;
    for (ll i = 1; i <= n; i++)
    {
        if (dsu_find(i) != dsu_find(1))
        {
            hs = false;
            break;
        }
    }
    if (hs)
    {
        printf("%lld %lld\n", cnt, cost);
    }
    else
    {
        printf("Not Possible\n");
    }
    return 0;
}