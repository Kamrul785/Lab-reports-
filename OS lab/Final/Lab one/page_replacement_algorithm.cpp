#include <bits\stdc++.h>
using namespace std;
int main()
{
    int frm, page;
    // cout << "Enter the number of frame : ";
    cin >> frm;
    int b[frm];
    // cout << "Enter the Number of Page : ";
    cin >> page;
    int a[page];
    // cout << "Enter the " << page << " pages " << endl;
    for (int i = 0; i < page; i++)
    {
        cin >> a[i];
    }
    int chk = -1;
    bool ok = false;
    int ans[frm][page];
    memset(b, -1, sizeof(b));
    memset(ans, -1, sizeof(ans));
    for (int i = 0; i < page; i++)
    {
        ok = false;
        for (int j = 0; j < frm; j++)
        {
            if (a[i] == b[j])
            {
                ok = true;
                break;
            }
        }
        if (!ok)
        {
            chk++;
            if (chk == frm)
                chk = 0;
            b[chk] = a[i];
        }
        for (int j = 0; j < frm; j++)
        {
            ans[j][i] = b[j];
        }
    }
    for (int i = 0; i < frm; i++)
    {
        for (int j = 0; j < page; j++)
        {
            if(ans[i][j] != -1) cout<<" ";
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}