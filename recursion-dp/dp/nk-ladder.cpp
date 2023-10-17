#include<bits/stdc++.h>
using namespace std;

//bottom up solution
int nK_ladderDP(int n, int k){  
    vector<int> dp(n+1, 0);
    dp[0] = 1;
    for(int i = 1; i<= n; i++){
        for(int j = 1; j<= k; j++){
            if( i-j >= 0)
                dp[i] += dp[i - j];
        }
    }
    return dp[n];
}
int countwaysOPT(int n, int k){
    vector<int> dp(n+1, 0);

    dp[0] = 1; dp[1] = 1;
    for( int i = 2; i<=k; i++){
        dp[i] = 2*dp[i-1];
    }
    for( int i = k+1; i<= n; i++){
        dp[i] = 2*dp[i-1] - dp[i-k-1];
    }
    return dp[n];
}
int main(){
    int n = 4, k = 3;
    cout<<nK_ladderDP(n, k)<<endl;
    return 0;
}
