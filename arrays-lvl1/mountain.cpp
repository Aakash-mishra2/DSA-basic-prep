#include <bits/stdc++.h>
using namespace std;

int mountain(vector<int> arr)
{
    int n = arr.size() - 1;
    int max_mountain = 0;

    int i = 1;
    while (i < arr.size() - 1)
    {
        if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1])
        {
            int left = i - 1, mountain_size = 3;
            while (left > 0 && arr[left] > arr[left - 1])
            {
                mountain_size++;
                left--;
            }
            i = i + 1;
            while (i < arr.size() - 1 && arr[i] > arr[i + 1])
            {
                i++;
                mountain_size++;
            }
            if (mountain_size > max_mountain)
            {
                max_mountain = mountain_size;
            }
        }
        i++;
    }
    return max_mountain;
}

int main()
{
    vector<int> arr = {5, 6, 1, 2, 3, 4, 5, 4, 3, 2, 0, 1, 2, 3, -2, 4};
    cout << mountain(arr);
    return 0;
}