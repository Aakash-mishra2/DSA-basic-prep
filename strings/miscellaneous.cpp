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

//router & houses

 vector<int> houses = {2, 4, 6};
    vector<int> routers = {4, 5};
    //find closest and farthest routers;
    
    int result = INT_MIN;
    for(auto house: houses){
        int it = lower_bound(routers, house);
        int leftDistance = (it != 0) ? house - routers[it-1] : INT_MAX;
        int rightDistance = (it != routers.size()-1) ? routers[it] - house : INT_MAX;
        
        int minDistance = min(leftDistance, rightDistance);
        
        result = max(minDistance, result);
    }
    
    cout<<result<<endl;
    

// envelope stacking 
class Solution {
    static bool cmp(vector<int>& a, vector<int>& b){
        if(a[0]==b[0]) return a[1] > b[1];
        return a[0] < b[0];
    }
public:
    int maxEnvelopes(vector<vector<int>>& env) {
        int n = env.size();
        
        std::sort(env.begin(), env.end(), cmp);
        vector<int> dp;
        for(const auto& envelope : env){
            int height = envelope[1];
            auto it = lower_bound(dp.begin(), dp.end(), height);
            if(it == dp.end()) dp.push_back(height);

            else *it = height;
        }

        return dp.size();
    }
};


