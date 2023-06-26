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

    char *s = strtok((char *)str.c_str(), " ");
    while (key > 1)
    {
        s = strtok(NULL, " ");
        key--;
    }

    return (string)s;
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
    for (int i = 0; i < n; i++)
    {
        vp.push_back({v[i], extractStringAtKey(v[i], key)});
    }

    // 2. sorting
    if (ordering == "lexicographic")
    {
        sort(vp.begin(), vp.end(), [](pair<string, string> p1, pair<string, string> p2)
             { return lexicographical_compare(p1.second.begin(), p1.second.end(), p2.second.begin(), p2.second.end()); });
    }
    if (ordering == "numeric")
    {
        sort(vp.begin(), vp.end(), [](pair<string, string> p1, pair<string, string> p2)
             {
            string input1 = p1.second;
            string input2 = p2.second;
            int num1 = convertToInt(input1);
            int num2 = convertToInt(input2);
            return num1 < num2; });
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