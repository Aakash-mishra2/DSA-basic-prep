#include<bits/stdc++.h>
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
void findSubstrings(int i, string str, string o, vector<string>& output){

if(i == str.length()){
  return;
}
 o = o + str[i];
 output.push_back(o);
 cout<<o<<" ";
 findSubstrings(i+1, str, o, output);
 return;
}
int countingAnagrams(vector<string> inputs){

}

int main(){
    file_io();
    string s;
    cin>>s;
    vector<string> inputSS;
    cout<<" All  substrings are : "<<endl;
    for( int i = 0; i<s.length(); i++){
    string o;
    findSubstrings(i, s, o, inputSS);
    }
    cout<<" Number of anagram pairs are : ";
    cout<<countingAnagrams(inputSS);
    return 0;
}
