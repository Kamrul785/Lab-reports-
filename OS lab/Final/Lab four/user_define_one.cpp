#include <bits/stdc++.h>
using namespace std;
const int N = 100;
void calculateNeed(int n, int r, int max_need[][N], int a[][N], int need[][N])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < r; j++)
        {
            need[i][j] = max(0, max_need[i][j] - a[i][j]);
        }
    }
}

bool isSafe(int n, int r, int a[][N], int need[][N], int avail[], vector<int> &ans)
{
    vector<bool> finish(n, false);
    while (ans.size() < n)
    {
        bool safe = false;
        for (int i = 0; i < n; i++)
        {
            if (finish[i])
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
                finish[i] = true;
                for (int j = 0; j < r; j++)
                {
                    avail[j] += a[i][j];
                }
                safe = true;
            }
        }
        if (!safe)
            return false;
    }
    return true;
}

void printans(const vector<int> &ans)
{
    cout << "Safe Sequence: ";
    for (size_t i = 0; i < ans.size(); i++)
    {
        cout << "P" << ans[i];
        if (i < ans.size() - 1)
            cout << " -> ";
    }
    cout << endl;
}

void updateResources(int n, int r, vector<pair<int, vector<int>>> req, int a[][N], int need[][N], int avail[])
{
    for (auto [p, request] : req)
    {
        bool flag = true;
        for (int i = 0; i < r; i++)
        {
            if (request[i] > need[p][i] || request[i] > avail[i])
            {
                flag = false;
                break;
            }
        }

        if (!flag)
        {
            cout << "Request for P" << p << " cannot be granted" << endl;
            continue;
        }
        cout << "Request for P" << p << " is granted" << endl;
        for (int i = 0; i < r; i++)
        {
            avail[i] -= request[i];
            a[p][i] += request[i];
            need[p][i] -= request[i];
        }
    }
}
int main()
{
    int n, r;
    cout << "Enter the number of pes and resources: ";
    cin >> n >> r;

    int a[N][N], max_need[N][N], need[N][N], avail[N];

    cout << "Enter the p a matrix:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < r; j++)
        {
            cin >> a[i][j];
        }
    }

    cout << "Enter the Maximum Need matrix:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < r; j++)
        {
            cin >> max_need[i][j];
        }
    }

    cout << "Enter the Available resources:\n";
    for (int i = 0; i < r; i++)
    {
        cin >> avail[i];
    }
    calculateNeed(n, r, max_need, a, need);
    vector<int> ans;
    int q;
    cout << "Enter the request Number :" << endl;
    cin >> q;
    cout << "Enter p No and request ";
    vector<pair<int, vector<int>>> req;
    while (q--)
    {
        vector<int> tmp;
        int pros;
        cin >> pros;
        for (int i = 0; i < r; i++)
        {
            int x;
            cin >> x;
            tmp.push_back(x);
        }
        req.push_back({pros, tmp});
    }
    updateResources(n, r, req, a, need, avail);
    if (isSafe(n, r, a, need, avail, ans))
    {
        printans(ans);
    }
    else
    {
        cout << "The Given Sequence is not safe." << endl;
    }

    return 0;
}
