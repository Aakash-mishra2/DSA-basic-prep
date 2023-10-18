#include <bits/stdc++.h>
using namespace std;

/*
void genPar(int n, string o, vector<string>& ans, int open = 0, int close = 0){
        if( close == n ){
            ans.push_back(o);
            return;
        }
        if(open <= n-1){
            genPar(n, o + '(', ans, open + 1, close);
        }
        if( close < open){
            genPar(n, o + ')', ans, open, close + 1);
        }
        return;
    }
    vector<string> generateParenthesis(int n) {
       vector<string> ans;
       string o = "";
       genPar(n, o, ans); 
        return ans;
    }
*/

void generateBrackets(int n, string ans, int open = 0, int close = 0, int i = 0)
{
    if (i == 2 * n)
    {
        cout << ans << endl;
        return;
    }
    if (open < n)
    {
        generateBrackets(n, ans + '(', open + 1, close, i + 1);
    }
    if (close < open)
    {
        generateBrackets(n, ans + ')', open, close + 1, i + 1);
    }
}

int main()
{
    int n;
    cin >> n;
    string ans = "";
    generateBrackets(n, ans);
    return 0;
}
