#include <bits/stdc++.h>
using namespace std;
// 45 ANSWER IS WRONG.

int knapsack(vector<int> weights, vector<int> prices, int N, int W)
{
    vector<vector<int> > dp(N + 1, vector<int>(W + 1, 0));
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            if (weights[i - 1] <= j)
            {
                dp[i][j] = max(dp[i - 1][j], (dp[i - 1][j - weights[i - 1]] + prices[i - 1]));
            }
        }
    }
    return dp[N][W];
}

int main()
{

    int N = 4, W = 11;
    // cin >> N >> W;

    vector<int> weights = {2, 7, 3, 4};
    vector<int> Prices = {5, 20, 20, 10};

    cout << knapsack(weights, Prices, N, W) << endl;

    return 0;
}