#include <bits/stdc++.h>
using namespace std;

void subsequences(string input, string output, vector<string> &vec, int i = 0)
{
    if (i == input.length())
    {
        vec.push_back(output);
        return;
    }

    // include
    subsequences(input, output + input[i], vec, i + 1);

    // exclude
    subsequences(input, output, vec, i + 1);
}
bool compare(string s1, string s2)
{
    if (s1.length() == s2.length())
    {
        return s1 < s2;
    }

    return s1.length() < s2.length();
}
int main()
{
    string input;
    cin >> input;
    vector<string> vec;
    string output;
    subsequences(input, output, vec);

    sort(vec.begin(), vec.end(), compare);

    for (auto a : vec)
    {
        cout << a << ", ";
    }
    return 0;
}