#include <bits/stdc++.h>
using namespace std;

int mountain(vector<int> arr)
{
    int n = arr.size();
    int i = 1, max_mntn = 0;
    for (int i = 1; i <= n - 2;)
    {
        if (arr[i] > arr[i + 1] and arr[i] > arr[i - 1])
        {
            int l = i - 1;
            i++;
            int mountain_size = 3;
            while ((l > 0) and (arr[l] > arr[l - 1]))
            {
                mountain_size++;
                l--;
            }
            while ((i < n - 1) and ((arr[i] > arr[i + 1])))
            {
                mountain_size++;
                i++;
            }
            if (mountain_size > max_mntn)
            {
                max_mntn = mountain_size;
            }
        }
        else
            i++;
    }
    return max_mntn;
}

int main()
{
    vector<int> arr = {5, 6, 1, 2, 3, 4, 5, 4, 3, 2, 0, 1, 2, 3, -2, 4};
    cout << mountain(arr);
    return 0;
}