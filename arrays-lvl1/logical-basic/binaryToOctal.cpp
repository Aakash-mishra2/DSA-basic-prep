#include <bits/stdc++.h>
using namespace std;
#define TOKEN_SIZE 3

vector<string> makebitTokens(string input)
{
    vector<string> ans;
    int i = 0, j = 0;
    string token;
    while (input[j] != '\0')
    {
        token += input[j];
        j++;
        if (token.length() == TOKEN_SIZE)
        {
            cout << token << endl;
            i = i + TOKEN_SIZE - 1;
            ans.push_back(token);
            token = "";
        }
    }
    ans.push_back(token);
    return ans;
}
int tokenToDecimal(string str)
{
    // int token = stoi(str);
    int ans = 0;
    int radix = 1;
    for (auto i : str)
    {
        ans += radix * (i - '0');
        radix = radix << 1;
    }
    cout << ans
         << endl;
    return ans;
}
string binaryToOctal(string input)
{
    std::reverse(input.begin(), input.end());
    vector<string> bitTokens = {};
    bitTokens = makebitTokens(input);
    string ansOctal = "";
    std::reverse(bitTokens.begin(), bitTokens.end());
    for (auto i : bitTokens)
    {
        ansOctal += to_string(tokenToDecimal(i));
    }
    return ansOctal;
}
int main()
{
    char ch1 = static_cast<char>(24);
    ch1 = ch1 << 1;
    cout << ch1 << endl;
    cout << "Enter binary string :";
    string bin;
    cin >> bin;
    cout << binaryToOctal(bin);
}