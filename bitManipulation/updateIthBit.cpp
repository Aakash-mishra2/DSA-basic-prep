#include<iostream>
using namespace std;
#include <bits/stdc++.h>
using namespace std;
void file_io()
{
    ios_base::sync_with_stdio;
    cout.tie(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("../arrays-lvl1/revn-1/input.txt", "r", stdin);
    freopen("../arrays-lvl1/revn-1/output.txt", "w", stdout);
#endif
}
void updateIthBit(int n, int i, int v){
    //clear ith bit anyways and mask will be diff acc to v auto ans.
    int mask = ~(1<<i);
    n = n&mask;
    mask = v<<i;
    n = n|mask;
    cout<<" New no. is  :"<<n;
}

int main(){
    file_io();
    int t; cin>>t;
    int i; cin>>i;
    while(t--){
        int x; cin>>x;
        int v; cin>>v;
        //update value of ith bit to v
        updateIthBit(x, i, v);
        cout<<endl;
    }
    return 0;
}