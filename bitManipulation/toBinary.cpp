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
int convToBinary(int m){
    int ans= 0, pow=1;
    while(m>0){
        int last_bit = m&1;
        if(last_bit){ ans += last_bit*pow; }
        pow *= 10; m = m>>1;
    }
    return ans;
}
int main(){
    file_io();
    int t; cin>>t;
    while(t--){
        int y; cin>>y;
        cout<<convToBinary(y);
        cout<<endl;
    }
    return 0;
}