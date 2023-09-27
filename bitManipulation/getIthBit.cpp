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
void getIthBit(int n, int i){
    int mask = 1<<i;
    if( n&mask >0)cout<<i<<" th bit is 1.";
    else cout<<2<<" th bit is 0.";
}

int main(){
    file_io();
    int t; cin>>t;
    int i; cin>>i;
    while(t--){
        int x; cin>>x;
        getIthBit(x, i);
        cout<<endl;
    }
    return 0;
}