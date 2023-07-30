#include <iostream>
using namespace std;

bool divideAmongK(vector<int> arr, int K, int minCoins)
{
    // return true when at least K partitions possible with minimum value of mid coins each.
    int partitions = 0, current_value = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (current_value + arr[i] >= minCoins)
        {
            partitions += 1;
            current_value = 0;
        }
        else
        {
            current_value += arr[i];
        }
    }
    return partitions >= K;
}

int getCoins(vector<int> arr, int K)
{
    // do not sort as we need work on given total value of subarrays possible.
    int s = 0, e = 0, ans = 0;
    for (auto ele : arr)
    {
        e = e + ele;
    }
    while (s <= e)
    {
        int mid = (e + s) / 2;
        bool isPossible = divideAmongK(arr, k, mid);
        if (isPossible)
        {
            ans = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {1, 8, 10, 12, 13, 14, 20, 22};
    int k = 3;
    cout << getCoins(arr, k);
    return 0;
}
