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
#include<bits/stdc++.h>
using namespace std;

void generateBrackets(int n, int i, string str, int open, int close){
    if ( i == 2*n){
        cout<<str<<endl;
        return;
    }
    if( open < n){
        generateBrackets(n, i+1, str+'(', open+1, close);
    }
    if( close < open){
        generateBrackets(n, i+1, str+')', open, close+1);
    }
    return;
}

int main()
{
    int t; cin>>t;
    while( t-- ){
        int n; cin>>n;
        generateBrackets(n, 0, "", 0, 0);
    }
    return 0;
}
