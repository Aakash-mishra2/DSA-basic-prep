#include <bits/stdc++.h>
using namespace std;
//  incomplete code -- lead to sum array calculated multiple times.
int sum[400][400];
int dp[400][400];
int min_costSlimes(vector<int> slimes, int l, int r)
{

    int N = slimes.size();

    if (dp[l][r] != -1)
    {
        return dp[l][r];
    }
    int mincost = INT_MAX;
    for (int k = l; k <= r; k++)
    {
        mincost = min(mincost, (min_costSlimes(slimes, l, k) + min_costSlimes(slimes, k + 1, r) + sum[l][r]));
    }

    return dp[l][r] = mincost;
}

int main()
{
    vector<int> slimes = {10, 20, 30, 40};
    int N = slimes.size();
    memset(sum, 0, sizeof(sum));
    memset(dp, -1, sizeof(dp));

    for (int i = 1; i <= N; i++)
    {
        for (int j = i; j <= N; j++)
        {
            sum[i][j] = slimes[j] + ((i == j) ? 0 : sum[i - 1][j]);
        }
    }
    cout << min_costSlimes(slimes, 0, N - 1);
    return 0;
}