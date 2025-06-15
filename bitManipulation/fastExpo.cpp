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
int pow(int a, int b){
    int res = 1;
    while( b ){
        if( b&1) res = res * a;
        a = a*a;
        b = b>>1;
}
    return res;
}

long long fastPower(long long base, long long expo) {
    long long result = 1;

    while (expo > 0) {
        if (expo & 1) {  // If the current bit is 1 (i.e., expo is odd)
            result *= base;
        }
        base *= base;     // Square the base
        expo >>= 1;       // Right shift expo (divide by 2)
    }

    return result;
}

int fastMultiply(int a, int b){
     ll res = 0;

    while(b){
        if( b & 1) res = res + a;
        a += a;
        b = b>>1;
    }
    return res;
}
int main(){
    file_io();
    int t; cin>>t;
    
    while(t--){
        int x; cin>>x;
        if(x&1)cout<<x<<" is odd"<<endl;
        else cout<<x<<" is even"<<endl;
    }
    return 0;
}
