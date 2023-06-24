#include <bits/stdc++.h>
using namespace std;
int countSubsets(vector<int> arr, int n, int i, int X)
{
    if (i == n)
    {
        if (X == 0)
        {
            return 1;
        }
        return 0;
    }
    int inc = countSubsets(arr, n, i + 1, X - arr[i]);
    int exc = countSubsets(arr, n, i + 1, X);
    return inc + exc;
}

int main()
{
    vector<int> array = {10, 12, 13, 6, 19, 20};
    int sum = 31;

    cout << countSubsets(array, array.size(), 0, sum);
}