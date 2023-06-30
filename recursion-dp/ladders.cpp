#include <bits/stdc++.h>
using namespace std;

int countWays(int x, int k)
{
    vector<int> dp(x + 1, 0);
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= x; i++)
        for (int z = 1; z <= k; z++)
        {
            if (i >= z)
                dp[i] += dp[i - z];
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