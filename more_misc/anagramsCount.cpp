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
    vector<int> freq(26, 0);
    //iterate over original string from i to j to fill this vector
    for(int k = i; k<=j; k++){
        freq[s[k] - 'a']++;
    }
    return freq;
}

int countingAnagrams(string str){
    map<vector<int>, int> M;
    for( int i = 0; i<str.length(); i++){
        for( int j = i; j<str.length(); j++){
            //Substring [i...j]
            auto hash = getHashValue(str, i, j);
            //put it inside map
            M[hash]++;
        }
    }

    //pairs
    int ans = 0;
    for( auto p : M){
        int freq = p.second;
        if(freq >= 2){
            // C(freq,2) pairs possible 
            ans += (freq) * (freq-1)/2;
        }
    }
    return ans;
}

int main(){
    file_io();
    string s;
    cin>>s;
    cout<<" Number of anagram pairs are : ";
    cout<<countingAnagrams(s);
    return 0;
}
