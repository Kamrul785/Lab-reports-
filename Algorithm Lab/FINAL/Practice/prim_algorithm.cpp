#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<pair<int, int>> adj[N];
bool vis[N];
int prim(int src, int n)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});
    int totalcost = 0;
    while (!pq.empty())
    {
        auto [w, u] = pq.top();
        pq.pop();
        if (vis[u])
            continue;
        vis[u] = true;
        totalcost += w;
        for (auto [v, weight] : adj[u])
        {
            if (!vis[v])
            {
                pq.push({weight, v});
            }
        }
    }
    return totalcost;
}
int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    memset(vis, false, sizeof(vis));
    int totalCost = prim(0, n);
    cout << totalCost << endl;
    return 0;
}