#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int s, int e)
{
    int pivot = arr[e];
    int i = s - 1, j = s;
    for (j = s; j < e; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    // do not swap with pivot it is a seperate variable not inside array.
    swap(arr[i + 1], arr[e]);
    return i + 1;
}
void quickSort(vector<int> &arr, int s, int e)
{
    if (s >= e)
    {
        return;
    }
    int index = partition(arr, s, e);
    quickSort(arr, s, index - 1);
    quickSort(arr, index + 1, e);
}

int main()
{
    vector<int> vec{10, 5, 2, 0, 6, 7, 4};
    quickSort(vec, 0, vec.size() - 1);
    for (auto i : vec)
    {
        cout << i << " ";
    }
    return 0;
}