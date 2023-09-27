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
void replaceBits(int n, int a, int b, int m){
    //clear a to b bits of n; //put m 
    int m1 = (-1<<a);
    int m2 = ~(-1<<b);
    int mask = m1|m2;
    n = n&mask;
    m = m<<b;
    n = n|m;
    cout<<"New no. is: "<<n;
}
int main(){
    file_io();
    int t; cin>>t;
    int a, b; cin>>b>>a;
    while(t--){
        int x; cin>>x;
        int y; cin>>y;
        replaceBits(x, a, b, y);
        cout<<endl;
    }
    return 0;
}