#include <bits/stdc++.h>
using namespace std;

pair<int, int> subarray_Sort(vector<int> arr)
{
    int n = arr.size();
    vector<int> b(arr);
    sort(b.begin(), b.end());
    int l = 0, r = n - 1;

    for (int i = 0; i < n / 2; i++)
    {
        if (arr[i] == b[i])
        {
            l++;
        }
        if (arr[n - i - 1] == b[n - i - 1])
        {
            r--;
        }
    }
    return make_pair(l, r);
}
bool outOfOrder(vector<int> arr, int i)
{
    // element larger that its successor is out of order
    //  element smaller that its previous is out of order
    int x = arr[i];
    // corner cases
    if (i == 0)
    {
        return x > arr[1];
    }
    if (i == arr.size() - 1)
    {
        return x < arr[i - 1];
    }

    return x > arr[i + 1] or x < arr[i - 1];
}

pair<int, int> subarray_SortPK(vector<int> arr)
{
    // smallest and largest element out of order approach.
    int smallest = INT_MAX;
    int largest = INT_MIN;
    for (int i = 0; i < arr.size(); i++)
    {
        int x = arr[i];

        if (outOfOrder(arr, i))
        {
            smallest = min(smallest, x);
            largest = max(largest, x);
        }
    }
    // find the right index where smallest and largest lie(subarray) for our solution.
    if (smallest == INT_MAX)
    {
        return {-1, -1};
    }
    if (smallest == INT_MAX)
    {
        return {-1, -1};
    }
    // find stpt and endpt of outOfOrder subarray
    int left = 0;
    while (smallest >= arr[left])
    {
        left++;
    }
    int right = arr.size() - 1;
    while (largest <= arr[right])
    {
        right--;
    }

    // return
    return {left, right};
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 8, 6, 7, 9, 10, 11};

    auto subArray = subarray_SortPK(arr);
    cout << subArray.first << " " << subArray.second;
    return 0;
}