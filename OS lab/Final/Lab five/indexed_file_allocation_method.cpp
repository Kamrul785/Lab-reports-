#include <bits/stdc++.h>
using namespace std;
const int N = 1000;
bool vis[N];
vector<int> a[N];
int main()
{
    memset(vis, false, sizeof(vis));
    do
    {
        vector<pair<int, vector<int>>> v;
        int idx;
        cout << "Enter the index block : ";
        cin >> idx;
        if (vis[idx])
        {
            cout << idx << " already allocated" << endl;
            continue;
        }
        vis[idx] = true;
        cout << "Enter no of blocks needed and no of files for the index " << idx << " : " << endl;
        int b;
        cin >> b;
        vector<int> file;
        for (int i = 0; i < b; i++)
        {
            int x;
            cin >> x;
            if (vis[x])
            {
                cout << x << " index already allocated" << endl;
                continue;
            }
            vis[x] = true;
            file.push_back(x);
        }
        v.push_back({idx, file});
        cout << "Allocated" << endl;
        cout << "File Indexed" << endl;
        for (auto [id, a] : v)
        {
            for (int i = 0; i < a.size(); i++)
            {
                cout<<id<<"---->"<<a[i]<<endl;
            }
        }
        cout<<"Do you want to enter more file ? "<<endl;
        cout<<"Enter 1 for Yes or 0 for NO : "<<endl;
        int key;
        cin>>key;
        if(key == 0){
            cout<<"Excecution complete"<<endl;
            break;
        }
    } while (true);
    return 0;
}
