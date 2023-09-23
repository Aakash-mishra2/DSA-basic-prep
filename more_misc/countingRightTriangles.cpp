
}
/*
Input:
5
1 2
2 0
2 2
2 3
4 2
Output:
4

Input:
3
0 0
2 0
0 1
Output:
1
*/

#include<bits/stdc++.h>
using namespace std;
//steps
//1. Generate all substrings.
//2. generate their Hash.
//3. create a hash of this Hash to club all anagrams with same hash value
//  in single bucket,to get their frequency count.
//4. From freq count, we can easily count pairs.
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

vector<int> getHashValue( string s, int i, int j){
    vector<int> vec(26, 0);
    for(int k = i; k<= j; k++){
        vec[s[k]-'a'] += 1;
    }
    return vec;
}

int countingAnagrams(string str){
    map<vector<int>, int> map;
    for(int i = 0; i<str.length(); i++){
        for(int j = i; j<str.length(); j++){
            auto thisHash = getHashValue(str,i,j);
            map[thisHash]++;
        }
    }
    int answer = 0;
    for(auto p : map){
        if(p.second > 1){ answer += (p.second)*(p.second - 1)/2; }
    }
    return answer;
}

int main(){
    file_io();
    string s;
    cin>>s;
    cout<<" Number of anagram pairs are : ";
    cout<<countingAnagrams(s);
    return 0;
}
