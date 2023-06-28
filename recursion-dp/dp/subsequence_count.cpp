#include <bits/stdc++.h>
using namespace std;

int subsequence_count(string x, string y, int i, int j)
{
    // base case
    if ((i == -1 and j == -1) or (j == -1))
    {
        return 1;
    }
    // first string finished second something still left;
    if (i == -1)
    {
        return 0;
    }

    int ans = 0;
    if (x[i] == y[j])
    {
        ans = (subsequence_count(x, y, i - 1, j - 1) + subsequence_count(x, y, i - 1, j));
    }
    else
        ans = subsequence_count(x, y, i - 1, j);

    return ans;
}

int subsequence_countBU(string s1, string s2)
{
    int m = s1.length(), n = s2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // the blank subsequence of s2 can be part of all the subsequences of s1
    for (int z = 0; z <= m; z++)
    {
        dp[z][0] = 1;
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {

            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[m][n];
}
int main()
{
    string s1 = "ABBCECDGCC", s2 = "ABC";
    // cin >> s1 >> s2;
    //    cout << subsequence_count(s1, s2, s1.length() - 1, s2.length() - 1) << endl;
    cout << subsequence_countBU(s1, s2) << endl;
}