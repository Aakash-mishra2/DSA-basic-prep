#include <bits/stdc++.h>
using namespace std;
// think about how to print longest inc subseq vector as well or string;
int longestIncSubsequence(vector<int> input)
{
    vector<int> dp(input.size(), 1);
    for (int i = 1; i < dp.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (input[j] <= input[i])
                dp[i] = max(dp[i], dp[j] + 1);
        }
    }
    int max = 0;
    for (auto a : dp)
    {
        if (a > max)
        {
            max = a;
        }
    }
    return max;
}

int main()
{

    vector<int> input = {50, 4, 10, 8, 30, 100};

    auto ans = longestIncSubsequence(input);
    cout << ans;
}