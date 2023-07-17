#include <bits/stdc++.h>
using namespace std;

int max_non_adjacent_sum(vector<int> input)
{
    vector<int> DP(input.size(), 0);
    DP[0] = input[0];
    DP[1] = max(input[0], input[1]);
    for (int i = 2; i < input.size(); i++)
    {
        DP[i] = max(DP[i - 1], DP[i - 2] + input[i]);
    }
    return DP[input.size() - 1];
}

int main()
{
    vector<int> arr = {6, 10, 12, 7, 9, 14};
    cout << max_non_adjacent_sum(arr);

    return 0;
}