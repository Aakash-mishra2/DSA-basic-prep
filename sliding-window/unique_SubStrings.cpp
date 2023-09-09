#include<bits/stdc++.h>
using namespace std;

string uniqueSubstring(string str){
    int start_idx, maxWindow = 0, windowLength = 0;
    int i =0, j = 0;
    unordered_map<char, int> M;
    while(j<str.length())
    {
        char ch = str[j];
        //if current character is read before
        // if its last occurence was after start of curr window
        if(M.count(ch) and M[ch] >= i){
            i = M[ch] + 1;
            windowLength = j - i; 
        }
        M[ch] = j;
        j++;
        windowLength++;
        if(windowLength > maxWindow){
            maxWindow  = windowLength;
            start_idx = i;
        }
    }
    return str.substr(start_idx, maxWindow);
}

int main(){
    string s1, s2;
    cin>>s1;
    cout<<" Largest substring with unique non-repeating characters : ";
    s2 = uniqueSubstring(s1);
    cout<<s2;
    return 0;
}
