#include <bits/stdc++.h>
using namespace std;

int selling_wines_TD(vector<int> wines, int l, int r, int dp[][10], int y = 1)
{

    if (l > r)
    {
        return 0;
    }
    if (dp[l][r] != 0)
    {
        return dp[l][r];
    }

    dp[l][r] = max((wines[l] * y + selling_wines_TD(wines, l + 1, r, dp, y + 1)), (wines[r] * y + selling_wines_TD(wines, l, r - 1, dp, y + 1)));

    return dp[l][r];
}

// to get dp[i][j] you want dp[i+1][j] and dp[i][j-1] precalculated
// that is right diagonal, row decreases, col increases
// taking n+1 size dp can solve AIOUB error i b w a 0,0 ?
// so handle a i==j separ.

int selling_winesBU_DP(vector<int> wines, int N)
{
    vector<vector<int>> dp(N + 1, vector<int>(N + 1, 0));

    for (int i = N - 1; i <= 0; i--)
    {
        for (int j = 0; j <= N - 1; j++)
        {
            int year = N - (j - i);

            if (i == j)
            {
                dp[i][i] = wines[i] * year;
            }

            else if (i < j)
            {

                dp[i][j] = max((wines[i] * year + dp[i + 1][j]), (wines[j] * year + dp[i][j - 1]));
                cout << dp[i][j] << ", ";
            }
        }
        cout << endl;
    }
    return dp[0][N - 1];
}

int main()
{
    vector<int> wines = {2, 3, 5, 1, 4};
    int l = 0, r = wines.size() - 1;

    int dp[10][10] = {0};

    cout << selling_wines_TD(wines, l, r, dp);
    // cout << selling_winesBU_DP(wines, wines.size());

    // print dp array

    return 0;
}

// int selling_winesBU_DP(vector<int> wines)
// {
//     int n = wines.size();
//     vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n, 0)));

//     int l = 0, r = n - 1;
//     for (int i = 1; i <= n; i++)
//     {
//         dp[l][r] = max((wines[l]*i + dp[l + 1][r]), (wines[r]*i + dp[l][r - 1]));
//     }
// }