#include <bits/stdc++.h>
using namespace std;

void fibonacci(int x){
    std::vector<int> dp(x, 0) ;

    dp[0] = 0; dp[1] = 1;
    for(int i = 2; i<x; i++){
        dp[i] = dp[i-1] + dp[i-2];
        cout<<dp[i]<<" ";
    }
    return;
}
int main()
{
    int t;
    cin>>t;
    while( t-- ){
        int n; cin>>n;
        cout<<" 0  1  ";
        fibonacci(n);
    }

    return 0;
}
