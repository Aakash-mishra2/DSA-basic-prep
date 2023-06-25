#include <bits/stdc++.h>
using namespace std;

int max_adjacent_sum(vector<int> input)
{
    int n = input.size();

    if (n == 1)
    {
        cout << input[0];
        return;
    }
    if (n == 2)
    {
        return max(0, max(input[0], input[1]));
    }

    vector<int> dp(n, 0);

    dp[0] = max(0, input[0]);
    dp[1] = max(input[0], input[1], 0);

    for (int i = 2; i < input.size(); i++)
    {
        dp[i] = max(dp[i - 2] + input[i], dp[i - 1], 0);
    }

    return dp[n - 1];
}

int main()
{
    vector<int> arr = {6, 10, 12, 7, 9, 14};
    cout << max_adjacent_sum(arr);

    return 0;
}