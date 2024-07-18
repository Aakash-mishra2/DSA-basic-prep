/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;

char* stringTokenizer(char *str, char delim){
    static char *input = NULL;
    if(str != NULL){
        input = str;
    };
    if( input == NULL){
        return NULL;
    }
    char *token = new char[strlen(input) + 1];
    int i = 0;
    for( ; input[i] != '\0'; i++){
       
        if( input[i] == delim){
            input += i + 1;
            token[i] = '\0';
            return token;
        }
        else 
            token[i] = input[i];
    }
    // out of the loop
    token[i] = '\0';
    input = NULL;
    return token;
}

int main(){
    
    char s[1000];
    cin.getline(s, 1000);
    char* token = stringTokenizer(s, ' ');
    while( token != NULL){
        cout<<token<<endl;
        token = stringTokenizer(NULL, ' ');
    }
    return 0;
}
