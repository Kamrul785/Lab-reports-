#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define fl float
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int a[n];
    for(int i =0 ;i<n;i++){
        cin>>a[i];
    }
    int key;
    cin>>key;
    bool flag = false;
    for(int i =0 ;i<n;i++){
        if(a[i] == key){
            flag = true;
            break;
        }
    }
    if(flag) cout<<"Key Found"<<endl;
    else cout<<"Key not Found"<<endl;
    return 0;
}