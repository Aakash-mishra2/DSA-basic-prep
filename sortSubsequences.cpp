#include <bits/stdc++.h>
using namespace std;

void getSubsequence(string input, string o, vector<string> &ans)
{
    if (input.size() == 0)
    {
        ans.push_back(o);
        return;
    }
    // // pick
    // getSubsequence(input, o + input[i], ans, i + 1);

    // getSubsequence(input, o, ans, i + 1);

    char ch = input[0];
    string reduced_input = input.substr(1);
    getSubsequence(reduced_input, o + ch, ans);
    getSubsequence(reduced_input, o, ans);
}
int main()
{

    string input = "abcd";
    cin >> input;
    string output = "";
    vector<string> ans;
    getSubsequence(input, output, ans);
    for (auto i : ans)
    {
        cout << i << " ,";
    }
    return 0;
}