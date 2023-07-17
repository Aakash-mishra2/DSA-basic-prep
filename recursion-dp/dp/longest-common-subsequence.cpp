#include <bits/stdc++.h>
using namespace std;

pair<int, string> longest_common_subsequence(string x, string y)
{
    vector<vector<int>> DP(x.length() + 1, vector<int>(y.length() + 1, 0));
    string ans;
    for (int i = 1; i < x.length(); i++)
    {
        for (int j = 1; j < y.length(); j++)
        {
            if (x[i - 1] == y[j - 1])
            {
                DP[i][j] = DP[i - 1][j - 1] + 1;
                ans += x[i - 1];
            }
            else
                DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
        }
    }
    return make_pair(DP[x.length() - 1][y.length() - 1], ans);
}

int main()
{
    string x = "ABCDE", y = "ABEDG";

    cout << endl
         << longest_common_subsequence(x, y).first
         << endl
         << longest_common_subsequence(x, y).second;
}