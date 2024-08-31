#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define fl float
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> a(n);
        for (ll i = 0; i < n; i++)
            cin >> a[i];
        sort(a.begin(), a.end());
        ll sum = 0;
        ll idx;

        for (ll i = 0; i < (n / 2); i++)
        {
            sum += (a[i] * (-1));
        }
        for (ll i = (n / 2); i < n; i++)
        {
            sum += a[i];
        }

        cout << sum << endl;
    }
    return 0;
}