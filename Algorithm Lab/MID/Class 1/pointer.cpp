#include <bits/stdc++.h>
#define endl '\n'
#define ll long long int 
#define fl float
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cout << "Enter two value: ";
    
    int n, m;
    cin >> n >> m;
    int *ptr = &n;

    cout << "Value of n: " << n << endl;
    cout << "Value pointed by ptr: " << *ptr << endl;

    *ptr = m;

    cout << "Updated value of n: " << n << endl;

    return 0;
}