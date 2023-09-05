#include <bits/stdc++.h>
using namespace std;

void file_io()
{
    ios_base::sync_with_stdio;
    cout.tie(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
bool isParenthesisRedundant(string str)
{
    // Complete
    stack<char> S;
    for (auto ch : str)
    {
        if (ch != ')')
        {
            S.push(ch);
        }
        else
        {
            bool optr = false;
            while (!S.empty() and S.top() != '(')
            {
                char temp = S.top();
                S.pop();
                if (temp == '+' or temp == '-' or temp == '*' or temp == '/')
                {
                    optr = true;
                }
                S.pop();
            }
            S.pop(); // pop the first opening bracket after loop is over
            if (optr == false)
            {
                return true;
            }
        }
    }
    return false;
}
int main()
{
    file_io();
    int t;
    cin >> t;
    // leave no white spaces bw input strings alphabets
    while (t--)
    {
        string operation;
        cin >> operation;
        if (isParenthesisRedundant(operation) == true)
            cout << "TRUE, Redundant!" << endl;
        else
            cout << "FALSE" << endl;
    }

    return 0;
}
