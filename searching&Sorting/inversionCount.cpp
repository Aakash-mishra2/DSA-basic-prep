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

int merge(vector<int> &vec, int s, int e)
{
    int count = 0;
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
            count += mid - i + 1;
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
    return count;
}

int invCount(vector<int> &vec, int s, int e)
{
    if (s >= e)
    {
        return 0;
    }
    int mid = (s + e) / 2;
    invCount(vec, s, mid - 1);
    invCount(vec, mid, e);
    return merge(vec, s, e);
}
// 10 5 2 0 7 6 4 -- 5
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << invCount(arr, 0, n - 1);
    return 0;
}