#include <bits/stdc++.h>
using namespace std;

// string.c_str() return const char*;

char *mytokenizer(char *input, char delimiter)
{
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
    for (; str[i] != '\0'; i++)
    {
        if (str[i] != delimiter)
        {
            token[i] = str[i];
        }
        else
        {
            token[i] = '\0';
            str = str + i + 1;
        }
    }

    token[i] = '\0';
    str = NULL;
    return token;
}

int main()
{
    // string input = "My home is near form bus stop. ";
    char input[1000];
    cin.getline(input, 1000);

    char *token = mytokenizer(input, ' ');
    while (token != NULL)
    {
        cout << token << endl;
        token = mytokenizer(NULL, ' ');
    }
    return 0;
}