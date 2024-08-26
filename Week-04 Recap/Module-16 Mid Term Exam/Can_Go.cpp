#include <bits/stdc++.h>
using namespace std;

typedef pair<long long int,long long int> pii;
const long long int N = 1e3 + 5;
vector<pii> v[N];
bool visited[N];
long long int dis[N];

void dijkstra(int s) 
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, s});
    dis[s] = 0;

    while (!pq.empty()) 
    {
        pii P = pq.top();
        pq.pop();
        int Pcost = P.first;
        int Pnode = P.second;
        
        if(visited[Pnode]) continue;
           visited[Pnode]=true;

        for (pii child : v[Pnode]) 
        {
            int childNode = child.first;
            int childCost = child.second;
            if (dis[Pnode] + childCost < dis[childNode]) 
            {
               dis[childNode] = dis[Pnode] + childCost;
               pq.push({dis[childNode], childNode});
            }
            
        }
    }
}

int main() 
{
    int n, e;
    cin >> n >> e;
    while (e--) 
    {
        int a, b, w;
        cin >> a >> b >> w;
        v[a].push_back({b, w});
    }
    for (int i = 1; i <= n; i++) 
    {
        dis[i] = INT_MAX;
    }

    int s;
    cin >> s;
    dijkstra(s);

    int t; cin>>t;
    while (t--) 
    {
        int d, dw;
        cin >> d >> dw;
        if (dis[d] <= dw) 
        {
            cout << "YES" << endl;
        } 
        else 
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}