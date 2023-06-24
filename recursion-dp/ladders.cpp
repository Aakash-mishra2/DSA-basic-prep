#include <bits/stdc++.h>
using namespace std;

int countWays(int x)
{
    if (x == 0)
    {
        return 1;
    }
    if (x < 0)
    {
        return 0;
    }
    return (countWays(x - 1) + countWays(x - 2) + countWays(x - 3));
}

int main()
{
    int n;
    cin >> n;
    cout << countWays(n);
    return 0;
}