#include <bits/stdc++.h>
using namespace std;
pair<int, int> pairs_(vector<int> arr, int target)
{
    unordered_set<int> M;
    int i = 0;
    while (i < arr.size())
    {
        int diff = target - arr[i];
        if (M.find(diff) == M.end())
        {
            M.insert(arr[i]);
            i++;
        }
        else
        {
            return make_pair(arr[i], diff);
        }
    }
    cout << " No such pair found" << endl;
}
int main()
{
    vector<int> arr{10, 5, 4, 2, 3, -6, 9, 11};
    int target = 4;
    auto s = pairs_(arr, target);
    cout << " [" << s.first << "," << s.second << "]" << endl;
    return 0;
}