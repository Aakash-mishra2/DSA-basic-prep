#include <bits/stdc++.h>
using namespace std;
//https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps-1587115620/1
//https://leetcode.com/problems/maximum-number-of-jumps-to-reach-the-last-index/description/
int count(int arr[], int n, vector<int>& dp, int ind){
        if(ind == n-1){ return 0; }
        if( ind >= n){ return INT_MAX;   }
        if( dp[ind] != 0){ return dp[ind]; }
        
        int maxJumps = arr[ind];
        int steps = INT_MAX;
        for(int i = 1; i<= maxJumps; i++){
            int next_cell = i + ind;
            int subProb = count(arr, n, dp, next_cell);
            if(subProb != INT_MAX){
                steps = min(steps, 1 + subProb);
            }
        }
        return  dp[ind] = steps;
    }

// recursive min array jumps
int minArrayJumps (int ind, int n, vector<int> arr){
    if( ind >= n-1 ){
       // cout<<ind<<" return "<<endl;
        return 0;
    }
    int ans = 10000000, jumps = arr[ind];
    for( int i = 1; i<=jumps; i++){
        ans = min(ans, 1 + minArrayJumps(ind + i, n, arr));
    }
    //cout<<ind<<" "<<n<<endl;
    return ans;
}
    int minJumps(int arr[], int n){
       vector<int> dp(n, 0);
       int ans = count(arr, n, dp, 0);
       if( ans == INT_MAX) return -1;
       else return ans;
    }
