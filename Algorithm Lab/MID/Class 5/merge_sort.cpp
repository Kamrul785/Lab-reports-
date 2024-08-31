#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define fl float
using namespace std;

void merge_sort(int a[], int b[], int l, int r)
{
    if (l == r)
        return;
    int mid = l + r / 2;
    merge_sort(a, b, l, mid);
    merge_sort(a, b, mid + 1, r);
    int i, j, k;
    for (int i = l, j = mid + 1, k = l; k < r;k++){
        if(i == mid+1) b[k] = a[j++];
        else if(j == r+1) b[k] = a[i++];
        else if(a[i] < a[j]) b[k] = a[i++];
        else b[k] = a[j++];
    }
    for(int k = l; k < r; k++) a[k] = b[k];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int a[n], b[n] = {0};
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        
    }
    merge_sort(a, b, 0, n - 1);
    for(auto x:b) cout<<x<<" ";
    return 0;
}