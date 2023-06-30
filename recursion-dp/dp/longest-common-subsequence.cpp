#include <bits/stdc++.h>
using namespace std;

int longest_common_subsequence(string x, string y)
{
    int m = x.length(), n = y.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {

            if (x[i - 1] == y[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                cout << x[i - 1] << " ";
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    cout << endl;
    return dp[m - 1][n - 1];
}

int main()
{
    string x = "ABCDE", y = "ABEDG";

    cout << endl
         << longest_common_subsequence(x, y);
}