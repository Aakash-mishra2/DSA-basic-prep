#include <bits/stdc++.h>
using namespace std;
void file_io()
{
    ios_base::sync_with_stdio;
    cout.tie(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
vector<int> mergeKsorted(vector<vector<int>> &arr)
{
    int k = arr.size();
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> q;

    // triplet-> element, index, array_index

    vector<int> output;
    // initialize heap
    for (int i = 0; i < k; i++)
    {
        int element = arr[i][0];
        q.push({element, 0, i});
    }

    // start popping
    while (!q.empty())
    {
        auto top = q.top();
        q.pop();
        int element = top.at(0);
        int element_index = top.at(1);
        int array_index = top.at(2);
        output.push_back(element);
        if (element_index + 1 < arr[array_index].size())
        {
            int next_element = arr[array_index][element_index + 1];
            q.push({next_element, element_index + 1, array_index});
        }
    }
    return output;
}

int main()
{
    file_io();
    vector<vector<int>> arr = {{10, 15, 20, 30},
                               {2, 5, 8, 14, 24},
                               {0, 11, 60, 90}};

    vector<int> ans = mergeKsorted(arr);

    for (auto x : ans)
    {
        cout << x << " ";
    }
    return 0;
}
