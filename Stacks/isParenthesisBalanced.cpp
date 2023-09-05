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
bool isParenthesisBalanced(string str)
{
    stack<char> s;
    for (auto ch : str)
    {
        switch (ch)
        {
        case '(':
        case '{':
        case '[':
        {
            s.push(ch);
            break;
        }
        case ')':
        {
            if (!s.empty() and s.top() == '(')
            {
                s.pop();
            }
            else
            {
                return false;
            }
            break;
        }

        case '}':
        {
            if (!s.empty() and s.top() == '{')
            {
                s.pop();
            }
            else
            {
                return false;
            }
            break;
        }

        case ']':
        {
            if (!s.empty() and s.top() == '[')
            {
                s.pop();
            }
            else
            {
                return false;
            }
            break;
        }

        default:
            continue;
        }
    }
    if (s.empty() == true)
    {
        return true;
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
        if (isParenthesisBalanced(operation) == true)
            cout << "TRUE" << endl;
        else
            cout << "FALSE" << endl;
    }

    return 0;
}
