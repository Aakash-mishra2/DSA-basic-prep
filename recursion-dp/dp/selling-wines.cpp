#include <bits/stdc++.h>
using namespace std;

int selling_wines_TD(vector<int> wines, int l, int r, int dp[][10], int y = 1)
{
}

// to get dp[i][j] you want dp[i+1][j] and dp[i][j-1] precalculated
// that is right diagonal, row decreases, col increases
// taking n+1 size dp can solve AIOUB error i b w a 0,0 ?
// so handle a i==j separ.

int selling_winesBU_DP(vector<int> wines, int N)
{
}

int selling_winesBU(vector<int> wines)
{
}

int main()
{
    vector<int> wines = {2, 3, 5, 1, 4};
    int l = 0, r = wines.size() - 1;

    int dp[10][10] = {0};

    // cout << selling_wines_TD(wines, l, r, dp);
    //  cout << selling_winesBU_DP(wines, wines.size());
    cout << selling_winesBU(wines);
    //   print dp array

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