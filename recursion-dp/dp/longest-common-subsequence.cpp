#include <bits/stdc++.h>
using namespace std;

int longest_common_subsequence(string x, string y)
{
    vector<vector<int>> dp(x.length() + 1, vector<int>(y.length() + 1, 0));

    for (int i = 1; i < x.length(); i++)
    {
        for (int j = 1; j < y.length(); j++)
        {

            if (x[i - 1] == y[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                cout << x[i - 1];
            }

            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[x.length() - 1][y.length() - 1];
}

int main()
{
    string x = "ABCDE", y = "ABEDG";

    cout << endl
         << longest_common_subsequence(x, y);
}