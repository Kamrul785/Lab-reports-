#include<bits/stdc++.h>
using namespace std;

class heap{
    public:
    int a[100];
    int size = 0;
    void insert(int val){
        size++;
        int idx = size;
        a[idx] = val;
        while(idx > 1){
            int par = idx / 2;
            if(a[par] < a[idx]){
                swap(a[par],a[idx]);
                idx = par;
            }
            else{
                return;
            }

        }
    }
    void print(){
        for(int i = 1;i<= size;i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
};

int main(){
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();
    return 0;
}