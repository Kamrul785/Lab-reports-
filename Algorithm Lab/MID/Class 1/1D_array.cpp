

//find a element of a given array of integers

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
    // cout << "Enter N: ";
    cin >> n;
    // cout << "Enter The Array : ";
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    // cout << "Enter an Element to find : ";
    int k;
    cin >> k;
    int l = 0, r = n - 1;
    bool ok = false;
    sort(a, a + n);
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (a[mid] == k)
        {
            ok = true;
            break;
        }
        else if (a[mid] > k)
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }

    if (ok)
        cout << "Found" << endl;
    else
        cout << "Not Found" << endl;
    return 0;
}