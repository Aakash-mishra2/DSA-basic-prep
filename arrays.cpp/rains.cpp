#include <bits/stdc++.h>
using namespace std;

int rains(vector<int> arr)
{
    int n = arr.size();
    vector<int> left(n, 0), right(n, 0);
    // int max = -1;
    // for (int i = 0; i < arr.size(); i++)
    // {
    //     if (arr[i] > max)
    //     {
    //         left[i] = arr[i];
    //     }
    //     else
    //         left[i] = max;
    // }
    // max = -1;
    // for (int i = arr.size() - 1; i >= 0; i--)
    // {
    //     if (arr[i] > max)
    //     {
    //         right[i] = arr[i];
    //     }
    //     else
    //         right[i] = max;
    // }
    left[0] = arr[0];
    int ans = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        ans += min(left[i], right[i]) - arr[i];
    }
    return ans;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    vector<int> arr{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 1, 2, 1};
    auto s = rains(arr);
    cout << s;
    return 0;
}