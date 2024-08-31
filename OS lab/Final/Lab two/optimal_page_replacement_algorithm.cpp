#include <bits/stdc++.h>
using namespace std;
int main()
{
    int frm, page;
    cin >> frm >> page;
    int a[frm], oc[frm];
    int b[page];
    for (int i = 0; i < page; i++)
    {
        cin >> b[i];
    }
    int cnt = 0;
    int mat[frm][page];
    char icon[page];
    memset(mat, -1, sizeof(mat));
    memset(oc, 100, sizeof(oc));
    memset(a, -1, sizeof(a));
    bool ok = false;
    for (int i = 0; i < page; i++)
    {
        ok = false;
        for (int j = 0; j < frm; j++)
        {
            if (b[i] == a[j])
            {
                ok = true;
                break;
            }
        }
        if (!ok)
        {
            icon[i] = 'X';
            cnt++;
            bool flag = false;
            for (int j = 0; j < frm; j++)
            {
                for (int k = i + 1; k < page; k++)
                {
                    if (a[j] == b[k])
                    {
                        oc[j] = k;
                        flag = true;
                        break;
                    }
                }
                if (!flag)
                {
                    oc[j] = page + 1;
                }
            }
            int mx = -1, mxidx = -1;
            for (int j = frm - 1; j >= 0; j--)
            {
                if (oc[j] >= mx)
                {
                    mx = oc[j];
                    mxidx = j;
                }
            }
            a[mxidx] = b[i];
        }
        if (icon[i] != 'X')
            icon[i] = 'O';
        for (int j = 0; j < frm; j++)
        {
            mat[j][i] = a[j];
        }
    }
    cout << "Page Fault : " << cnt << endl;
    for (int i = 0; i < frm; i++)
    {
        for (int j = 0; j < page; j++)
        {
            if (mat[i][j] != -1)
                cout << " ";
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < page; i++)
    {
        cout << " " << icon[i] << " ";
    }

    return 0;
}