#include <bits/stdc++.h>
using namespace std;
void file_i_o()
{
    ios_base::sync_with_stdio;
    cout.tie(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
void maxSubArrayK(vector<int> a, int k)
{
    // algorithm
    int n = a.size(), i = 0;
    deque<int> Q(k); // hold indices
    // 1. process only the first k elements

    for (i = 0; i < k; i++)
    {
        while (!Q.empty() && a[i] > a[Q.back()])
            Q.pop_back();

        Q.push_back(i);
    }

    // 2. remaining the elements of the array
    for (; i < n; i++)
    {
        // remove elements from left (contraction when an index lies outside the current window)

        cout << a[Q.front()] << " ";

        while (!Q.empty() and Q.front() <= i - k)
        {
            Q.pop_front();
        }

        while (!Q.empty() && a[i] >= a[Q.back()])
            Q.pop_back();

        // always
        Q.push_back(i);
    }
}
int main()
{
    file_i_o();
    vector<int> arr{1, 2, 3, 1, 4, 5, 2, 3, 5};
    int k = 3;

    maxSubArrayK(arr, k);

    return 0;
}
