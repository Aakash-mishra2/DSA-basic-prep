#include <bits/stdc++.h>
using namespace std;

int countWays(int x, int k)
{
    vector<int> dp(x + 1, 0);
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= x; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            if (i - j >= 0)
            {
                dp[i] += dp[i - j];
            }
        }
    }
    return dp[x];
}

int main()
{
    int n, k;
    cin >> n >> k;
    cout << countWays(n, k);
    return 0;
}