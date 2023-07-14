#include <bits/stdc++.h>
using namespace std;
// 45 ANSWER IS WRONG.

int knapsack(vector<int> weights, vector<int> prices, int N, int W)
{
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