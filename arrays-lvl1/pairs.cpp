#include <bits/stdc++.h>
using namespace std;
pair<int, int> pairs_(vector<int> arr, int target)
{
}
int main()
{
    vector<int> arr{10, 5, 4, 2, 3, -6, 9, 11};
    int target = 4;
    auto s = pairs_(arr, target);
    cout << " [" << s.first << "," << s.second << "]" << endl;
    return 0;
}