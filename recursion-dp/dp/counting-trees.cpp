#include <bits/stdc++.h>
using namespace std;
int counting_trees(int nodes)
{
    vector<int> dp(nodes + 1, 0);

    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= nodes; i++)
    {
        for (int j = 0; j < i; j++)
        {
            dp[i] += (dp[j - 1] * dp[i - j]);
        }
    }
    return dp[nodes];
}

int main()
{

    int n;
    cin >> n;

    cout << counting_trees(n) << endl;

    return 0;
}