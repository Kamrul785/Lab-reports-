#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define fl float
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> bt(n);
    // cout<<"Enter the Burst time : ";
    for (int i = 0; i < n; i++)
    {
        cin >> bt[i].first;
        bt[i].second = i + 1;
    }

    sort(bt.begin(), bt.end());

    int wt[n], tr[n];
    wt[0] = 0;
    for (int i = 1; i < n; i++)
    {
        wt[i] = wt[i - 1] + bt[i - 1].first;
    }
    for (int i = 0; i < n; i++)
    {
        tr[i] = wt[i] + bt[i].first;
    }

    cout << "Process\tBurst Time\tWaiting Time\tTurn Around Time" << endl;
    for (int i = 0; i < n; i++)
    {
        cout<<"P" << bt[i].second << "\t\t\t" << bt[i].first << "\t\t\t" << wt[i] << "\t\t\t\t" << tr[i] << endl;
    }
    float sumwt = 0, sumtr = 0;
    for (int i = 0; i < n; i++)
    {
        sumwt += wt[i];
        sumtr += tr[i];
    }
    cout << "Average Waiting time : " << sumwt / n << endl;
    cout << "Average Turn Around Time : " << sumtr / n << endl;

    for (int i = 0; i < floor(n * 6.33); i++)
        cout << ".";
    cout << endl;
    cout << "|" << 0 << "|";
    for (int i = 0; i < n; i++)
    {
        cout << "P" << bt[i].second << "|" << tr[i] << "|";
    }
    cout << endl;
    for (int i = 0; i < floor(n * 6.33); i++)
        cout << ".";
    cout << endl;

    return 0;
}