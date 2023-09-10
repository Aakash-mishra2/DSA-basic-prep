#include<bits/stdc++.h>
using namespace std;


vector<char> FindFirstNonRepeatingCharacter(string S){
    vector<char> nonRep;
    cout<<S<<endl;
    unordered_map<char, int> M;
    queue<char> q;
    for( auto ch : S){
        M[ch]++;
        if(M[ch]==1){
        q.push(ch);
        }
        while(!q.empty()){
            if(M[q.front()] > 1){
                q.pop();
            }
            else{
                nonRep.push_back(q.front());
                break;
            }
        }
        if(q.empty()){
            nonRep.push_back('0');
        }
    }
    
    return nonRep;
}
