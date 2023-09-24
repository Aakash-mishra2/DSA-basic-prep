#include<bits/stdc++.h>
using namespace std;
void file_io(){
    ios_base::sync_with_stdio;
    cout.tie(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("../MORE_miscc/input.txt", "r", stdin);
        freopen("../MORE_miscc/output.txt", "w", stdout);
    #endif
    }
bool isParBal(string str){
    stack<char>s;
    for(auto ch : str){
        switch(ch){
            case '(':
            case '{':
            case '[':
                        s.push(ch);
                        break;
            case '}':{
                if(!s.empty() and s.top()=='{') {s.pop(); continue;}
                else return false;
            }break;
            case ')': {
                if(!s.empty() and s.top()=='(') {s.pop(); continue;}
                else return false;
            }break;
            case ']': {
                if(!s.empty() and s.top()=='[') {s.pop(); continue;}
                else return false;
            }
            break;
            default: continue;
        }
    }
    if(s.empty()) return true;  
    return false;
}
int main(){
    file_io();
    int t; cin>>t;
    while(t--){

    string s;
    cin>>s;
    if(isParBal(s)) cout<<"Is Balanced"<<endl;
    else cout<<"Not balanced! "<<endl;
    }
}
