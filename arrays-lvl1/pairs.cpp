#include <bits/stdc++.h>
using namespace std;
pair<int, int> pairs_(vector<int> arr, int target)
{
    unordered_set<int> S;
    for (int i = 0; i < arr.size(); i++)
    {
        int diff = target - arr[i];
        if (S.find(diff) == S.end())
        {
            return make_pair(arr[i], diff);
        }
        else
        {
            S.insert(arr[i]);
        }
        return {-1, -1};
    }
}
int main()
{
    vector<int> arr{10, 5, 4, 2, 3, -6, 9, 11};
    int target = 4;
    auto s = pairs_(arr, target);
    cout << " [" << s.first << "," << s.second << "]" << endl;
    return 0;
}