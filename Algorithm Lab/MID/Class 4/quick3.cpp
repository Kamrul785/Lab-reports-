#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define fl float
using namespace std;
void swap(int a[], int i, int j)
{
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}
int partition(int a[], int l, int h)
{
    int pivot = a[l];
    int i = l, j = h;
    while (i < j)
    {
        do
        {
            i++;
        } while (a[i] <= pivot);
        do
        {
            j--;
        } while (a[j] > pivot);
        if (i < j)
        {
            swap(a, i, j);
        }
    }
    swap(a,l,j);
    return j;
}
void quickSort(int a[], int l, int h)
{
    if (l < h)
    {
        int j = partition(a, l, h);
        quickSort(a, l, j);
        quickSort(a, j + 1, h);
    }
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    quickSort(a, 0, n);
    for(auto x:a){
        cout<<x<<" ";
    }
    return 0;
}