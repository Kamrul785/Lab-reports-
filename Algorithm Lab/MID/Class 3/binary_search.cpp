#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define fl float
using namespace std;
int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i =0 ;i<n;i++) cin>>a[i];
    int key;
    cin>>key;
    sort(a.begin(),a.end());
    int ans = -1 ;
    int l = 0,r = n-1;
    while(l<=r){
        int mid = l + (r-l)/2;
        if(a[mid]==key){
            ans = mid;
            break;
        }
        else if(key < a[mid]){
            r = mid - 1;
        }
        else{
            l =  mid + 1;
        }
    }
    for(auto x: a){
        cout<<x<<" ";
    }
    cout<<endl;
    if(ans == -1){
        cout<<"Key not found "<<endl;
    }
    else{
        cout<<"Key found in index "<<ans <<endl;
    }
    return 0;
}