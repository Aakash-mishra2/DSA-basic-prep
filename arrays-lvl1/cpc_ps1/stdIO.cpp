#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    for_each(s1.begin(), s1.end(), [](char &c)
             { c = ::toupper(c); });
    for_each(s2.begin(), s2.end(), [](char &c)
             { c = ::toupper(c); });
    cout << -1 * static_cast<bool>(s1 < s2);
    return 0;
}