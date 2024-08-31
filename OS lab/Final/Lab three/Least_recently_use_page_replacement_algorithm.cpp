#include <bits/stdc++.h>
using namespace std;
int findidx(int frm, int pos[])
{
    int mn = INT_MAX, mnidx = -1;
    for (int j = 0; j < frm; j++)
    {
        if (pos[j] < mn)
        {
            mn = pos[j];
            mnidx = j;
        }
    }
    return mnidx;
}

bool check(int frm, int b[], int page, int &id)
{
    for (int j = 0; j < frm; j++)
    {
        if (b[j] == page)
        {
            id = j;
            return true;
        }
    }
    return false;
}

void update(int frm, int page, int mat[][100], int b[])
{
    for (int j = 0; j < frm; j++)
    {
        mat[j][page] = b[j];
    }
}

int main()
{
    int frm, page;
    cin >> frm >> page;
    int a[page], b[frm], pos[frm];
    int mat[frm][100]; 
    memset(mat, -1, sizeof(mat));
    memset(pos, -1, sizeof(pos));
    memset(b, -1, sizeof(b));

    for (int i = 0; i < page; i++)
        cin >> a[i];

    int cnt = 0;
    for (int i = 0; i < page; i++)
    {
        int id = -1;
        if (!check(frm, b, a[i], id))
        {
            cnt++;
            int idx = findidx(frm, pos);
            pos[idx] = i;
            b[idx] = a[i];
        }
        else
        {
            pos[id] = i;
        }
        update(frm, i, mat, b);
    }
    cout << "Page Fault : " << cnt << endl<<endl;
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
    return 0;
}
