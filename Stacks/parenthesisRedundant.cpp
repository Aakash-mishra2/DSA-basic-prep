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
    stack<char> s;
    for(auto ch : str){
        if( ch != ')'){ s.push(ch); }

        else {
            bool optr = false;
            while(!s.empty() and s.top()!='('){
            char temp = s.top();
            if(temp == '+' or temp =='-' or temp == '*' or temp=='/'){
                optr = true;    
            }
            s.pop();
            if(optr == false) return true;
        }
        s.pop(); //remove the last '('
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
