#include <bits/stdc++.h>
using namespace std;
vector<int> v[100];
bool vis[100];
void bfs(int scr)
{
    queue<int> q;
    q.push(scr);
    vis[scr] = true;
    while (q.empty() == false)
    {
        int parent = q.front();
        q.pop();
        cout << parent << " ";
        for (int i = 0; i < v[parent].size(); i++)
        {
            int child = v[parent][i];
            if (vis[child] == false)
            {
                q.push(child);
                vis[child] = true;
            }
        }
    }
}
int main()
{
    int n, e;
    cin >> n >> e;
    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    memset(vis, false, sizeof(vis));
    int scr;
    cin >> scr;
    bfs(scr);
    return 0;
}