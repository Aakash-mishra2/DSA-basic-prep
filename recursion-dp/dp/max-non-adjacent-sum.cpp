#include <bits/stdc++.h>
using namespace std;

int max_non_adjacent_sum(vector<int> input)
{
    int m = input.size();
    vector<int> dp(m + 1, 0);
    dp[0] = input[0];
    dp[1] = max(input[0], input[1]);

    for (int i = 2; i < m; i++)
    {
        dp[i] = max(dp[i - 2] + input[i], dp[i - 1]);
    }
    return dp[m - 1];
}

int main()
{
    vector<int> arr = {6, 10, 12, 7, 9, 14};
    cout << max_non_adjacent_sum(arr);

    return 0;
}