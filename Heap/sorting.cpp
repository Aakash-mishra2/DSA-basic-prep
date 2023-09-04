#include <iostream>
#include <queue>
using namespace std;
void file_io()
{
    ios_base::sync_with_stdio;
    cout.tie(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

class compare
{
public:
    bool operator()(int a, int b)
    {
        return a > b;
    }
};

int main()
{
    file_io();
    int arr[] = {10, 15, 20, 13, 9, 6, 90};
    int n = sizeof(arr) / sizeof(int);
    // max heap
    priority_queue<int> heap;
    for (int x : arr)
    {
        heap.push(x);
    }
    while (!heap.empty())
    {
        cout << heap.top() << endl;
        heap.pop();
    }

    // min heap
    priority_queue<int, vector<int>, compare> heap2;
    for (int x : arr)
    {
        heap2.push(x);
    }
    while (!heap2.empty())
    {
        cout << heap2.top() << endl;
        heap2.pop();
    }

    return 0;
}
