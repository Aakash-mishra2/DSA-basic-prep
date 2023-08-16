#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

bool comparator(string s1, string s2)
{
    return s1 + s2 < s2 + s1;
}

int main()
{
    string arr[] = {"a", "ab", "aba"};
    int n = 3;
    sort(arr, arr + n, comparator);
    for (auto s : arr)
    {
        cout << s;
    }
    return 0;
}