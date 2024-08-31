#include <bits/stdc++.h>
using namespace std;
int main()
{
    
    cout << "Enter the Number of Process : " ;
    int n;
    cin >> n;
    cout << n <<endl;
    int BT[n], TA[n], WT[n];
    float sumTA = 0, sumWT = 0;

    cout << "Enter the Burst Time of the Process : ";
    for (int i = 0; i < n; i++)
    {
        cin >> BT[i];
        cout << BT[i] <<" ";
    }
    cout << endl;

    TA[0] = BT[0];
    WT[0] = 0;
    sumTA += TA[0], sumWT += WT[0];

    for (int i = 1; i < n; i++)
    {
        TA[i] = TA[i - 1] + BT[i];
        WT[i] = TA[i - 1];
        sumTA += TA[i];
        sumWT += WT[i];
    }
    float avgTA = sumTA / n;
    float avgWT = sumWT / n;
    cout << endl;

    cout << "Process\tBurst Time\tTurn Around Time\tWaiting Time" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "\t" << i + 1 << "\t\t" << BT[i] << "\t\t\t " << TA[i] << "\t\t\t\t\t" << WT[i] << endl;
    }
    cout<<endl;
    cout << "Average Turn Around Time : " << avgTA << endl;
    cout << "Average Wating time : " << avgWT << endl <<endl;

    for(int i = 0; i< floor(n * 6.33) ; i++) cout<<".";
    cout<<endl;
    cout << "|" << 0 << "|";
    for (int i = 0; i < n; i++)
    {
        cout << "P" << i + 1 << "|" << TA[i] << "|";
    }
    cout << endl;
    for(int i = 0; i< floor(n * 6.33) ; i++) cout<<".";
    cout<<endl;


    return 0;
}