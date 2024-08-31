#include <bits/stdc++.h>
using namespace std;
vector<int> v[10005];
bool vis[10005];
int parent[10005];
bool ans;
void dfs(int par)
{
    // cout << src << " ";
    vis[par] = true;
    for (int child : v[par])
    {
        if(vis[child] && parent[par] != child){
            ans = true;
        }
        if(!vis[child]){
            parent[child] = par;
            dfs(child);
        }
    }
}
int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    memset(vis, false, sizeof(vis));
    memset(parent,-1,sizeof(parent));
    ans = false;
    for(int i = 0;i<n;i++){
        if(!vis[i]){
            dfs(i);
        }
    }
    if(ans){
        cout<<"Cycle Detected";
    }
    else{
        cout<<"NO Cycle Found"<<endl;
    }
    return 0;
}