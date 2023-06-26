#include <bits/stdc++.h>
using namespace std;

bool checkSubsets(string big, string small)
{
    int i = 0, j = 0;
    while (i < big.length())
    {
        if (big[i] == small[j])
        {
            i++;
            j++;
        }
        else
            i++;
    }
    if (j == small.length())
    {
        return true;
    }
    return false;
}

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    string big = "coding minutes";
    string small = "cines";
    cout << checkSubsets(big, small);
    return 0;
}