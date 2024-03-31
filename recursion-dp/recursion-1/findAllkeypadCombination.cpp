#include<bits/stdc++.h>
using namespace std;

int keypad = ["", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"]

void findAllCombination( string input, string output, int i = 0){
    if (input[i]=='\0'){
        cout<<output<<endl;
        return;
    }
    
    int curr_digit = input[i] - '0';
    if( curr_digit == 0 or curr_digit == 1){
        findAllCombination(input, output, i+1);
    }
    for( int k=0; k<keypad[curr_digit].size(); k++){
        findAllCombination(input, output + keypad[curr_digit][k], i+1);
    }
    return;
}

int main(){
    string n; cin>>n;
    findAllCombination(n);    
    
    return 0;
}
