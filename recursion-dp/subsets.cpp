#include <bits/stdc++.h>
using namespace std;
// asks subset not subarray
int countSubsets(vector<int> arr, int n, int i, int X)
{
    int count = 0;
    if (i == n)
    {
        if (X == 0)
        {
            // found one more way to get subset sum = x.
            count++;
        }
        return count;
    }

    return countSubsets(arr, n, i + 1, X - arr[i]) + countSubsets(arr, n, i + 1, X);
}

int main()
{
    vector<int> array = {10, 12, 13, 6, 19, 20};
    int sum = 31;

    cout << countSubsets(array, array.size(), 0, sum);
}