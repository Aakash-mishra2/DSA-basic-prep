#include <bits/stdc++.h>
using namespace std;
//  incomplete code -- lead to sum array calculated multiple times.
int min_costSlimes(vector<int> slimes, int l, int r, int sum[][400])
{

    int N = slimes.size();

    int dp[N + 1][N + 1];
    memset(dp, -1, sizeof(dp));

    if (dp[l][r] != -1)
    {
        return dp[l][r];
    }
    int mincost = INT_MAX;
    for (int k = l; k <= r; k++)
    {
        mincost = min(mincost, (min_costSlimes(slimes, l, k, sum) + min_costSlimes(slimes, k + 1, r, sum) + sum[l][r]));
    }

    return dp[l][r] = mincost;
}

int main()
{
    vector<int> slimes = {10, 20, 30, 40};
    int N = slimes.size();
    int sum[N + 1][N + 1];
    memset(sum, 0, sizeof(sum));
    for (int i = 1; i <= N; i++)
    {
        for (int j = i; j <= N; j++)
        {
            sum[i][j] = slimes[j] + ((i == j) ? 0 : sum[i - 1][j]);
        }
    }
    cout << min_costSlimes(slimes, 0, N - 1, sum);
    return 0;
}