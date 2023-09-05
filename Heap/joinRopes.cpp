#include <bits/stdc++.h>
#include <algorithm>

using namespace std;
class compare
{
public:
    bool operator()(int a, int b)
    {
        return a > b;
    }
};
int joinRopes(vector<int> &ropes)
{
    priority_queue<int, vector<int>, compare> heap(ropes.begin(), ropes.end());
    int answer = 0;
    while (heap.size() > 1)
    {
        int A = heap.top();
        heap.pop();
        int B = heap.top();
        heap.pop();

        int newRope = A + B;
        answer += newRope;
        heap.push(newRope);
    }
    return answer;
}
int main()
{
    vector<int> ropes = {4, 3, 2, 6};
    int N = 4;
    cout << joinRopes(ropes);
    return 0;
}
