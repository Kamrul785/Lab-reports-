#include <bits/stdc++.h>
using namespace std;
vector<int> v[10005];
bool vis[10005];
int level[10005];
int parent[10005];
void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;
    level[src] = 0;
    while (!q.empty())
    {
        int par = q.front();
        q.pop();
        cout << par << " ";
        for (int child : v[par])
        {
            if (!vis[child])
            {
                q.push(child);
                vis[child] = true;
                level[child] = level[par] + 1;
                parent[child] = par;
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
        int a, b, c;
        cin >> a >> b>> c;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    memset(vis, false, sizeof(vis));
    int src;
    cin >> src;
    memset(parent, -1, sizeof(parent));
    bfs(src);
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << i << " -> " << level[i] << endl;
    }
    cout << endl;
    int des;
    cin >> des;
    int x = des;
    vector<int>path;
    while(x != -1){
        path.push_back(x);
        x = parent[x];
    }
    reverse(path.begin(),path.end());
    for(int val : path){
        cout<<val <<" ";
    }
    return 0;
}