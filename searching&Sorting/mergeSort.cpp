#include <iostream>
#include <vector>
using namespace std;

void file_I_O()
{
    ios_base ::sync_with_stdio;
    cout.tie(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

void merge(vector<int> &vec, int s, int e)
{
    int i = s;
    int mid = (s + e) / 2;
    int j = mid + 1;
    vector<int> temp;
    while (i <= mid and j <= e)
    {
        if (vec[i] < vec[j])
        {
            temp.push_back(vec[i]);
            i++;
        }
        else
        {
            temp.push_back(vec[j]);
            j++;
        }
    }
    while (i <= mid)
    {
        temp.push_back(vec[i++]);
    }
    while (j <= mid)
    {
        temp.push_back(vec[j++]);
    }
    int k = 0;
    for (int idx = s; idx <= e; idx++)
    {
        vec[idx] = temp[k++];
    }
    return;
}

void mergeSort(vector<int> &vec, int s, int e)
{
    if (s >= e)
    {
        return;
    }
    int mid = (s + e) / 2;
    mergeSort(vec, s, mid - 1);
    mergeSort(vec, mid, e);
    return merge(vec, s, e);
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    mergeSort(arr, 0, n - 1);
    for (auto i : arr)
    {
        cout << i << " ";
    }
    return 0;
}