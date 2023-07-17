#include <bits/stdc++.h>
using namespace std;
// 45 ANSWER IS WRONG.

int knapsack(vector<int> weights, vector<int> prices, int N, int W)
{
    vector<vector<int>> DP(N + 1, vector<int>(W + 1, 0));

    for (int n = 1; n <= N; n++)
    {
        for (int w = 1; w <= W; w++)
        {
            if (weights[n - 1] <= w)
            {
                DP[n][w] = max((DP[n - 1][w]), (DP[n - 1][w - weights[n - 1]] + prices[n - 1]));
            }
        }
    }
    return DP[N][W];
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