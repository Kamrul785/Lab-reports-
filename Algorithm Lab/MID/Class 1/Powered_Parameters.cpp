#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define fl float
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        ll n, cnt = 0;
        cin >> n;
        vector<ll> a(n + 1);
        map<ll, ll> mp;
        for (ll i = 1; i <= n; i++)
        {
            cin >> a[i];
            mp[a[i]]++;
        }
        for (ll i = 1; i <= n; i++)
        {
            if (a[i] == 1)
            {
                cnt += n;
            }
            else
            {
                for (ll j = 1; j <= n; j++)
                {
                    ll res = pow(a[i], j);
                    if (res > 1e9)
                        break;
                    if (res <= a[j])
                        cnt++;
                }
            }
        }
        cout << cnt << endl;
    }

    return 0;
}
