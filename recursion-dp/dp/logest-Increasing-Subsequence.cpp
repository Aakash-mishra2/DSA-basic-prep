#include <bits/stdc++.h>
using namespace std;
// think about how to print longest inc subseq vector as well or string;
int longestIncSubsequence(vector<int> input)
{
    vector<int> DP(input.size(), 1);
    for (int i = 1; i < input.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (input[j] <= input[i])
            {
                DP[i] = max(DP[i], DP[j] + 1);
            }
        }
    }

    int max = 0;
    for (auto val : DP)
    {
        if (val > max)
        {
            max = val;
        }
    }
    return max;
}

int main()
{

    vector<int> input = {50, 4, 10, 8, 30, 100};

    auto ans = longestIncSubsequence(input);
    cout << ans;
}