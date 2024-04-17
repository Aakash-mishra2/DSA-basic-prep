#include <bits/stdc++.h>
using namespace std;
// think about how to print longest inc subseq vector as well or string;
void longestIncreasingSubSeq(int ind, vector<int> values, int n){
    
    vector<int> dp(n, 1); int max_len;
    dp[0] = 1;
    for (int i = 1; i<n; i++) {
        for(int j = 0; j<i; j++) {
            if( values[j] < values[i])
            dp[i] = max(dp[i], 1+dp[j]);
            max_len = max(dp[i], max_len);
        }
    }
    
    // for(auto a : dp){
    //     cout<<a<<" ";
    // }
    cout<< max_len;
    
}
int main()
{

    vector<int> input = {50, 4, 10, 8, 30, 100};

    auto ans = longestIncSubsequence(input);
    cout << ans;
}
