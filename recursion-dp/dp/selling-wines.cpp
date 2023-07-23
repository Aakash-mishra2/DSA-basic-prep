#include <bits/stdc++.h>
using namespace std;

int selling_wines_TD(vector<int> wines, int l, int r, int dp[][10], int y)
{
    if (l > r)
    {
        return 0;
    }
    if (dp[l][r] != 0)
    {
        return dp[l][r];
    }
    int pick_left = y * wines[l] + selling_wines_TD(wines, l + 1, r, dp, y + 1);
    int pick_right = y * wines[r] + selling_wines_TD(wines, l, r - 1, dp, y + 1);

    return dp[l][r] = max(pick_right, pick_left);
}

// to get dp[i][j] you want dp[i+1][j] and dp[i][j-1] precalculated
// that is right diagonal, row decreases, col increases
// taking n+1 size dp can solve AIOUB error i b w a 0,0 ?
// so handle a i==j separ.

int selling_winesBU_DP(vector<int> wines, int N)
{
    vector<vector<int>> dp(N + 1, vector<int>(N + 1, 0));
    for (int l = N - 1; l >= 0; l--)
    {
        for (int r = 0; r < N; r++)
        {
            // right upper triangle
            int year = N - (r - l);
            if (l == r)
            {
                dp[l][r] = wines[l] * year;
            }
            if (l < r)
            {
                int pick_left = wines[l] * year + dp[l + 1][r];
                int pick_right = wines[r] * year + dp[l][r - 1];
                dp[l][r] = max(pick_left, pick_right);
                cout << dp[l][r] << ",";
            }
        }
        cout << endl;
    }
    return dp[0][N - 1];
}

int selling_wines(vector<int> wines, int L, int R, int y)
{
    if (L > R)
    {
        return 0;
    }
    int pick_left = y * wines[L] + selling_wines(wines, L + 1, R, y + 1);
    int pick_right = y * wines[R] + selling_wines(wines, L, R - 1, y + 1);

    return max(pick_left, pick_right);
}

int main()
{
    vector<int> wines = {2, 3, 5, 1, 4};
    int l = 0, r = wines.size() - 1;

    int dp[10][10] = {0};

    // cout << selling_wines_TD(wines, l, r, dp);
    cout << selling_winesBU_DP(wines, wines.size());
    // cout << selling_wines(wines, l, r, 1);
    //    print dp array
    return 0;
}
