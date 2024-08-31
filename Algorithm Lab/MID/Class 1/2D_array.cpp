
// sum of primary and secondary diagonal

#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define fl float
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int a[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }

    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                sum1 += a[i][j];
            }
            if ((i + j) == (n - 1))
            {
                sum2 += a[i][j];
            }
        }
    }
    cout << "Primay Diagonal Sum : " << sum1 << endl;
    cout << "Secondary Diagonal Sum : " << sum2 << endl;
    return 0;
}