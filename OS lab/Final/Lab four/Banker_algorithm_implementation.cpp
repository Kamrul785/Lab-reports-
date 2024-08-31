#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, r;
    // cout<<"Enter the number of process and resource :";
    cin >> n >> r;
    int a[n][r], max_need[n][r], need[n][r], avail[r];
    // cout<<"Enter the process Allocation :"<<endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < r; j++)
        {
            cin >> a[i][j];
        }
    }
    // cout<<"Enter the max_needimum need "<<endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < r; j++)
        {
            cin >> max_need[i][j];
        }
    }
    // cout << "Enter the available resouce :" << endl;
    for (int i = 0; i < r; i++)
        cin >> avail[i];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < r; j++)
        {
            need[i][j] = max(0, max_need[i][j] - a[i][j]);
        }
    }
    vector<int> ans;
    bool vis[n];
    memset(vis, false, sizeof(vis));
    int safe = 0;
    while (ans.size() < n)
    {
        if (safe > 2 * n)
            break;
        for (int i = 0; i < n; i++)
        {
            if (vis[i])
                continue;
            bool ok = true;
            for (int j = 0; j < r; j++)
            {
                if (need[i][j] > avail[j])
                {
                    ok = false;
                    break;
                }
            }
            if (ok)
            {
                ans.push_back(i);
                vis[i] = true;
                for (int j = 0; j < r; j++)
                {
                    avail[j] += a[i][j];
                }
            }
        }
        safe++;
    }
    if (safe > 2 * n)
    {
        cout << "The Given Sequence is not safe.." << endl;
    }
    else
    {
        cout << "The Safe Sequence is : " << endl;
        for (int i = 0; i < n; i++)
        {
            cout << "P" << ans[i];
            if (i < n - 1)
                cout << " -> ";
        }
    }
    return 0;
}