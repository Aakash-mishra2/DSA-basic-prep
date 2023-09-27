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
void isTwoPower(int n){
    //equality operator has higher precedence
    if( (n&(n-1)) == 0){ cout<<" Yes no. is power of 2. ";}
    else cout<< " Nahi hai! ";
}
int main(){
    file_io();
    int t; cin>>t;
    while(t--){
        int x; cin>>x;
        isTwoPower(x);
        cout<<endl;
    }
    return 0;
}