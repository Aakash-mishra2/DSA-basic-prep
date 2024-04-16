#include <bits/stdc++.h>
using namespace std;

// int max_non_adjacent_sum(vector<int> input)
// {
//     vector<int> dp(input.size(), 0);
//     dp[0] = input[0];
//     dp[1] = max(input[0], input[1]);
//     for (int i = 2; i < input.size(); i++)
//     {
//         dp[i] = max(dp[i - 1], dp[i - 2] + input[i]);
//     }
//     int max = 0;
//     for (auto a : dp)
//     {
//         if (a > max)
//         {
//             max = a;
//         }
//     }
//     return max;
// }

void maxNonAdjacentSum(int ind, vector<int> values, int n){
    vector<int>dp (n, 0);
    dp[0] = values[0];
    dp[1] = max(dp[0], values[1]);
    for(int i = 2; i<n; i++){
        
        dp[i] = max(dp[i-1], dp[i-2] + values[i]);
        
    }
    // for(auto a : dp){
    //     cout<<a<<" ";
    // }
    cout<< endl<< dp[n-1];    
}

int main()
{
    vector<int> arr = {6, 10, 12, 7, 9, 14};
    cout << max_non_adjacent_sum(arr);

    return 0;
}
