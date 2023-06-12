#include <iostream>
#include <cstring>
using namespace std;

char *myTokenizer(char *str, char delimiter)
{
    char *input = NULL;
    if (str != NULL)
    {
        input = str;
    }
    if (input == NULL)
    {
        return NULL;
    }
    char *token = NULL;
    int i = 0;
    for (; input[i] != '\0', i++)
    {
        if (input[i] != delimiter)
        {
            token[i] = input[i];
            i++;
        }
        else
        {
            token[i] = '\0';
            input = input + i + 1;
            return token;
        }
    }
    token[i] = '\0';
    input = NULL;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    char s[1000];
    cin.getline(s, 1000);

    char *token = myTokenizer(s, ' ');

    while (token != NULL)
    {
        cout << token << endl;
        token = myTokenizer(NULL, ' ');
    }

    return 0;
}