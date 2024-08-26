#include <bits/stdc++.h>
using namespace std;
 
int parent[1000];
int parentLevel[1000];
 
void dsu_set(int n)
{
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
        parentLevel[i] = 0;
    }
}
 
int dsu_find(int node)
{
    if (parent[node] == node)
    {
        return node;
    }
    return parent[node] = dsu_find(parent[node]); // Path compression
}
 
void dsu_union(int a, int b)
{
    int leaderA = dsu_find(a);
    int leaderB = dsu_find(b);
    if (leaderA != leaderB)
    {
        if (parentLevel[leaderA] > parentLevel[leaderB])
        {
            parent[leaderB] = leaderA;
        }
        else if (parentLevel[leaderB] > parentLevel[leaderA])
        {
            parent[leaderA] = leaderB;
        }
        else
        {
            parent[leaderB] = leaderA;
            parentLevel[leaderA]++;
        }
    }
}
 
int main()
{
    int n;
    cin >> n;
    dsu_set(n);
    vector<pair<int, int>> plan;
    vector<pair<int, int>> p;
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        int leaderA = dsu_find(a);
        int leaderB = dsu_find(b);
        if (leaderA != leaderB)
        {
            dsu_union(a, b);
            plan.push_back({a, b});
        }
        else
        {
            p.push_back({a, b});
        }
    }
 
    vector<int> v;
    for (int i = 1; i <= n; i++)
    {
        int la = dsu_find(i);
        if (la == i)
        {
            v.push_back(i);
        }
    }
    int i=0;
    cout << p.size() << endl;
    for (auto pr : p)
    {
        cout << pr.first << " " << pr.second << " " << v[i] << " "<<v[i+1] << endl;
        i++;
    }
    return 0;
}