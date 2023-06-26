// given list of 'n' strings s0, s1, s2, ... sN-1, each consisting of digits and spaces, the number
// of spaces is the same for each entry, the goal is to implement a variation of a sort command. None
// of the strings contains consecutive spaces. Also, no string starts with a space nor ends with it.
// spaces are used to divide string into columns, which can be used as keys in comparisions.
/* input
3
80 122 64
92 20 15
87 45 43
2 false lexicographic
*/
#include <vector>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;
string extractStringAtKey(string str, int key)
{
    // cannot use const_cast<char*>(str); ->
    // strtok ( char *, const char* );
    char *token = strtok(const_cast<char *>((str).c_str()), " ");
    while (key > 1)
    {
        token = strtok(NULL, " ");
        key--;
    }

    return static_cast<string>(token);
}
int convertToInt(string s)
{
    int num1 = 0;
    for (int i = 0; i < s.length(); i++)
    {
        num1 += s[i] - '0';
        num1 *= 10;
    }
    return num1;
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    cin.get(); // for consuming extra n
    string temp;
    vector<string> v;
    for (int i = 0; i < n; i++)
    {
        getline(cin, temp);
        v.push_back(temp);
    }

    int key;
    string reversal, ordering;
    cin >> key >> reversal >> ordering;

    // 1. to extract keys for comparision and store them.
    vector<pair<string, string>> vp;
    for (auto str : v)
    {
        vp.push_back(make_pair(str, extractStringAtKey(str, key)));
    }
    // 3. reversal
    if (reversal == "true")
    {
        reverse(vp.begin(), vp.end());
    }

    // 4. output
    for (int i = 0; i < n; i++)
    {
        cout << vp[i].first << endl;
    }

    return 0;
}