#include <bits/stdc++.h>
using namespace std;

string checkSubsets(string big, string small)
{

    int i = 0, j = 0;
    while (i < big.length())
    {
        if (big[i] == small[j])
        {
            i++;
            j++;
        }
        i++;
    }
    if (j == small.length())
    {
        return "YES";
    }
    else
    {
        return "NO";
    }
}

int main()
{
    string big = "coding minutes";
    string small = "cines";
    cout << checkSubsets(big, small);
    return 0;
}