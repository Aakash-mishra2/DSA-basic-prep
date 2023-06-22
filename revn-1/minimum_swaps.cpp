#include <bits/stdc++.h>
using namespace std;

// unique - substrings
int minimum_swaps(vector<int> input, int i = 0)
{
    vector<pair<int, int>> vec;
    for (int i = 0; i < input.size(); i++)
    {
        vec.push_back(make_pair(input[i], i));
    }
    sort(vec.begin(), vec.end());
    vector<bool> visited(input.size(), false);
    int answer = 0;

    for (int i = 0; i < input.size(); i++)
    {
        if (visited[i] == true or vec[i].second == i)
        {
            continue;
        }

        int curr = i;
        int cycle_size = 0;
        while (visited[curr] == false)
        {
            visited[curr] = true;
            curr = vec[curr].second;
            cycle_size++;
        }
        answer += cycle_size - 1;
    }

    return answer;
}

int main()
{
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    vector<int> arr = {5, 4, 3, 2, 1};
    cout << minimum_swaps(arr) << endl;
    return 0;
}