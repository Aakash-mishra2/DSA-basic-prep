#include <bits/stdc++.h>
using namespace std;
//https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps-1587115620/1
//https://leetcode.com/problems/maximum-number-of-jumps-to-reach-the-last-index/description/
int maxNonAdjacentSum(vector<int> steps){
    int n = steps.size();
    vector<int> dp(n, 0);
    dp[0] = steps[0];
    dp[1] = max(dp[0], steps[1]);
    for(int i = 2; i < n; i++){
        dp[i] = max(dp[i-2] + steps[i], dp[i-1]);
    }
    return dp[n-1];
}

// recursive min array jumps
int minArrayJumps(vector<int> steps){
    int n = steps.size();
    vector<int> dp( n, 1e9 + 7);
    dp[n-1] = 0;
    for(int i = n-2; i>= 0; i--){
    int max_jumps = steps[i];
        for(int j = 1; j<= max_jumps; j++){
            if( i + j <= n-1){
                dp[i] = min(dp[i], dp[i+j] + 1);
            }
        }
    }
    return dp[0];
}
   int minJumps(int arr[], int n){
       vector<int> dp(n, 0);
       int ans = count(arr, n, dp, 0);
       if( ans == INT_MAX) return -1;
       else return ans;
    }
