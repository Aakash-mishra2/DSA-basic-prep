#include<iostream>
#include<unordered_set>
#include<climits>
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
using namespace std;

string s = "thequickbrownfoxjumpsoverthehighbridge";

string words[] = {"the", "fox", "thequickbrownfox", "jumps", "lazy", "lazyfox",
                    "highbridge", "the", "over", "bridge", "high", "tall",
                    "quick", "brown"};

int min_barsHelper(string s, string words[], int idx, unordered_set<string> &m){
//base case
    if(s[idx] == '\0'){
        return 0;
    }
//recursive case
    int ans = INT_MAX;
    string current_string = "";
    for( int j=idx; s[j]!='\0'; j++){
        current_string += s[j];

        if(m.find(current_string)!=m.end()){
            int remaining_ans = min_barsHelper(s, words, j+1, m);
            if(remaining_ans != -1){
                ans = min(ans, 1+remaining_ans);
            }
        }
    }
    if( ans == INT_MAX){
        return -1;
    }
    return ans;
}

int min_bars(){
    unordered_set<string> m;
    for( auto i : words){
        m.insert(i);
    }
    //recursive helper function
    int output = min_barsHelper(s, words, 0, m);
    return output - 1;
}
int main(){
    file_io();
    cout<<min_bars()<<endl;
    return 0;
}
