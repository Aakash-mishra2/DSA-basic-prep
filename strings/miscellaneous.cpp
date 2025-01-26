//https://leetcode.com/discuss/interview-question/6087768/Hashedin-(by-Deloitte)-Online-Assessment-Questions-2024
//dictinary & sentence

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string sentence = "this is sentence string is this";
    string dictionary = "GDB online is an online compiler and debugger tool sentence for C, C++, Python, Java, PHP, Ruby, Perl, C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C";
    
    unordered_map<string, vector<int>> mpp;
    
    vector<string> vecArr, vecArr2;
    int n1 = sentence.length();
    int n2 = dictionary.length();
    
    string temp = "";
    for(int i=0; i<=n1; i++){
        if(i == n1 || sentence[i] == ' '){
            vecArr.push_back(temp);
            temp = "";
        }
        else temp += sentence[i];
    }
    
    for(int i=0; i<vecArr.size(); i++) mpp[vecArr[i]].push_back(i);
    for(auto [word, indices]: mpp){
        if(dictionary.find(word) != string::npos){
            for(auto ind: indices) vecArr[ind] = "###";
        }
    }
    
    string ans = "";
    for(auto ele : vecArr) {
        ans += ele + " ";
    }
    
    cout<<"ans: "<<ans.substr(0, ans.size()-1)<<endl;
    
    
    return 0;
}


