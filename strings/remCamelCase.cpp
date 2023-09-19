//accenture mock test 19 sept messed up : no idea to use tolower(), islower() etc.

//given string in camelCase (1) print first letter starting capital (2) new line at end of each word (3) small first letter for rest of words

#include <iostream>

using namespace std;

int main()
{
    string s ="helloWorld";
    cout<<(char)toupper(s[0]);
  
    for(int i = 1; i<s.length();i++){
        if(isupper(s[i])){
            cout<<endl<<(char)tolower(s[i]);
        }
        else{
            cout<<s[i];
        }
    }
    return 0;
}
