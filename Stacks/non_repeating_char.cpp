#include<bits/stdc++.h>
using namespace std;

void file_io(){
    ios_base::sync_with_stdio;
    cout.tie(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}

int main(){
    file_io();
    string s;
    cin>>s;
    queue<char> q;
    unordered_map<char, int> m;
    for( int i = 0; i<s.length(); i++){
        m[s[i]]++;
        if(m[s[i]] == 1){ q.push(s[i]); }
        while(!q.empty()){
            if(m[q.front()] == 1){
                cout<<q.front()<<" ";
                break;
            }
            else{
                q.pop();
            }
        }
        if(q.empty()) cout<<'-1'<<" ";
    }
    return 0;
}
