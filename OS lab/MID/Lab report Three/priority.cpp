#include <bits/stdc++.h>
using namespace std;
struct Process
{
    int idx, bt, at, rt, pr;
};
bool cmp(Process a, Process b)
{
    if (a.pr == b.pr)
        return a.at < b.at;
    return a.pr > b.pr;
}
int main()
{
    int n;
    // cout << "Enter number of Process: ";
    cin >> n;
    vector<Process> task(n);
    // cout << "Enter burst time , arrival time and priority for each process:" << endl;
    for (int i = 0; i < n; i++)
    {
        task[i].idx = i + 1;
        cin >> task[i].bt >> task[i].at >> task[i].pr;
        task[i].rt = task[i].bt;
    }
    sort(task.begin(), task.end(), cmp);
    int done = 0, time = 0, mn = INT_MAX;
    int smallidx = 0, finish_time;
    bool flag = false;
    vector<int> wt(n, 0), tr(n, 0);

    while (done != n)
    {
        // Find process with minimum remaining time at this time
        for (int j = 0; j < n; j++)
        {
            if ((task[j].at <= time) && (task[j].rt < mn) && (task[j].rt > 0))
            {
                mn = task[j].rt;
                smallidx = j;
                flag = true;
            }
        }

        if (!flag)
        {
            time++;
            continue;
        }

        // Reduce remaining time by one
        task[smallidx].rt--;

        // Update minimum
        mn = task[smallidx].rt;
        if (mn == 0)
        {
            mn = INT_MAX;
        }

        // If a process gets completely executed
        if (task[smallidx].rt == 0)
        {
            done++;
            flag = false;

            finish_time = time + 1;
            wt[smallidx] = finish_time - task[smallidx].bt - task[smallidx].at;

            if (wt[smallidx] < 0)
            {
                wt[smallidx] = 0;
            }
        }
        time++;
    }

    // Calculate turnaround time
    for (int i = 0; i < n; i++)
    {
        tr[i] = task[i].bt + wt[i];
    }

    // Output the results
    cout << "Process\tBurst Time\tArrival Time\tWaiting Time\tTurn Around Time" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "P" << task[i].idx << "\t\t\t" << task[i].bt << "\t\t\t" << task[i].at << "\t\t\t\t" << wt[i] << "\t\t\t\t" << tr[i] << endl;
    }

    float sumwt = 0, sumtr = 0;
    for (int i = 0; i < n; i++)
    {
        sumwt += wt[i];
        sumtr += tr[i];
    }
    cout << "Average Waiting Time: " << sumwt / n << endl;
    cout << "Average Turn Around Time: " << sumtr / n << endl;

    for (int i = 0; i < floor(n * 6.33); i++)
        cout << ".";
    cout << endl;

    cout << "|0|";
    int currTime = 0;
    for (int i = 0; i < n; i++)
    {
        currTime += task[i].bt;
        cout << "P" << task[i].idx << "|" << currTime << "|";
    }
    cout << endl;

    for (int i = 0; i < floor(n * 6.33); i++)
        cout << ".";
    cout << endl;

    return 0;
}