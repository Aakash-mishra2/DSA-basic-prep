#include <bits/stdc++.h>
#include <string>
using namespace std;

char *myTokenizer(char *input, char delimiter)
{
    //    static char, traverse on it till '/0';
    //    if ith = deliliter tokem '/0' return token;
    //    other wise token[i] = input[i];
    static char *str = NULL;
    if (input != NULL)
    {
        str = input;
    }
    if (str == NULL)
    {
        return NULL;
    }
    char *token = new char[strlen(str) + 1];
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] == delimiter)
        {
            token[i] = '\0';
            str = str + i + 1;
            return token;
        }
        else
        {
            token[i] = str[i];
        }
        i++;
    }
    // OUT OF LOOP
    token[i] = '\0';
    // ONCE YOU HAVE EXTRACTED ALL TOKENS
    str = NULL;
    return token;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    char input[1000];
    cin.getline(input, 1000);
    char *res = myTokenizer(input, ' ');
    while (res != NULL)
    {
        cout << res << endl;
        res = myTokenizer(NULL, ' ');
    }
    return 0;
}