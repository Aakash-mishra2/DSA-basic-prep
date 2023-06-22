// pairs - two pointers/ no
//  Given a string, write a function to replace all whitespaces with %20.
//  write a fxn to replace all spaces in a string with '%20'. It is given that the string has sufficient
//  space at the end to hold the additional characters.
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

vector<vector<int>> triplets(vector<int> arr, int S)
{
    sort(arr.begin(), arr.end());
    vector<vector<int>> result;
    for (int i = 0; i < arr.size() - 3; i++)
    {
        int first = arr[i];
        int target = S - arr[i];
        int s = i + 1, e = arr.size() - 1;
        while (s < e)
        {
            if ((arr[s] + arr[e]) == target)
            {
                result.push_back({arr[i], arr[s], arr[e]});
                s++;
                e--;
            }
            else if ((arr[s] + arr[e]) > target)
                e--;
            else
                s++;
        }
    }
    return result;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    vector<int> arr{10, 5, 2, 3, -6, 9, 11};
    int S = 4;

    auto s = triplets(arr, S);

    return 0;
}