#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define fl float
using namespace std;

struct Process
{
    int idx;
    int bt; 
    int at; 
    int rt;
};

int main()
{
    int n, time_slice;
    // cout << "Enter number of Process: ";
    cin >> n;
    // cout << "Enter the time_slice: ";
    cin >> time_slice;
    vector<pair<int, int>> gct;
    vector<Process> task(n);
    // cout << "Enter burst time and arrival time for each process:" << endl;
    for (int i = 0; i < n; i++)
    {
        task[i].idx = i + 1;
        cin >> task[i].bt >> task[i].at;
        task[i].rt = task[i].bt;
    }

    int time = 0;
    queue<int> q;
    vector<int> wt(n, 0), tr(n, 0);
    vector<bool> flag(n, false);

    int done = 0;
    while (done < n)
    {
        for (int i = 0; i < n; i++)
        {
            if (task[i].at <= time && !flag[i] && task[i].rt > 0)
            {
                q.push(i);
                flag[i] = true;
            }
        }

        if (q.empty())
        {
            time++;
            continue;
        }

        int j = q.front();
        q.pop();
        flag[j] = false;

        int ex_time = min(time_slice, task[j].rt);
        time += ex_time;
        task[j].rt -= ex_time;
        gct.push_back({task[j].idx, time});
        for (int i = 0; i < n; i++)
        {
            if (i != j && task[i].at <= time && task[i].rt > 0 && !flag[i])
            {
                q.push(i);
                flag[i] = true;
            }
        }

        if (task[j].rt > 0)
        {
            q.push(j);
            flag[j] = true;
        }
        else
        {
            done++;
            wt[j] = time - task[j].bt - task[j].at;
            if (wt[j] < 0)
                wt[j] = 0;
            tr[j] = wt[j] + task[j].bt;
        }
    }

    // Output the results
    cout << "Process\tBurst Time\tWaiting Time\tTurn Around Time" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "P" << task[i].idx << "\t\t\t" << task[i].bt << "\t\t\t" << wt[i] << "\t\t\t\t" << tr[i] << endl;
    }

    float sumwt = 0, sumtr = 0;
    for (int i = 0; i < n; i++)
    {
        sumwt += wt[i];
        sumtr += tr[i];
    }
    cout << "Average Waiting Time: " << sumwt / n << endl;
    cout << "Average Turn Around Time: " << sumtr / n << endl;
    cout << endl;
    // Gantt chart
    cout << "Gantt chart:" << endl;
    for (int i = 0; i < 2 * (n * n + 1); i++)
        cout << ".";
    cout << endl;
    cout << "|0|";
    for (auto a : gct)
    {
        cout << "p" << a.first << "|" << a.second << "|";
    }
    cout << endl;
    for (int i = 0; i < 2 * (n * n + 1); i++)
        cout << ".";
    cout << endl;

    return 0;
}
