#include <bits/stdc++.h>
using namespace std;
// think about how to print longest inc subseq vector as well or string;
int longestIncSubsequence(vector<int> input)
{
    int n = input.size();
    vector<int> dp(n, 1);

    for (int z = 1; z < n; z++)
    {
        for (int i = 0; i < z; i++)
        {
            if (input[i] <= input[z])
            {
                dp[z] = max(dp[z], (dp[i] + 1));
            }
        }
    }

    int max = 0;
    for (auto i : dp)
    {
        if (i > max)
        {
            max = i;
        }
    }
    return max;
}

int main()
{

    vector<int> input = {50, 4, 10, 8, 30, 100};

    auto ans = longestIncSubsequence(input);
    cout << ans;
    // cout << ans.size();
    // for (auto i : ans)
    // {
    //     cout << ans << " ";
    // }
    // return 0;
}