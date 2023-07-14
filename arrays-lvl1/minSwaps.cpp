#include <bits/stdc++.h>
using namespace std;
// non intersecting cycles of swaps
int countMinSwaps(vector<int> arr)
{
    vector<pair<int, int>> vec;
    for (int i = 0; i < arr.size(); i++)
    {
        vec.push_back(make_pair(arr[i], i));
    }
    sort(vec.begin(), vec.end());

    vector<bool> visited(arr.size(), false);
    int ans = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        int current_position = i;
        if (visited[i] == true or vec[current_position].second == i)
        {
            continue;
        }
        int cycle = 0;
        while (visited[current_position] == false)
        {
            visited[current_position] = true;
            cycle += 1;
            current_position = vec[current_position].second;
        }
        ans += cycle - 1;
    }
    return ans;
}
int main()
{
    vector<int> arr{5, 4, 3, 2, 1};
    cout << countMinSwaps(arr) << endl;
    return 0;
}