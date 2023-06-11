// Given a string, write a function to replace all whitespaces with %20.
// write a fxn to replace all spaces in a string with '%20'. It is given that the string has sufficient
// space at the end to hold the additional characters.

#include <iostream>
using namespace std;

char *newSpaces(char *input)
{

    int i = 0, count = 0;
    for (; input[i] != '\0'; i++)
    {
        if (input[i] == ' ')
        {
            count++;
        }
    }

    int ne = i + 2 * (count);
    while (ne > i)
    {
        if (input[i] == ' ')
        {
            input[ne--] = '0';
            input[ne--] = '2';
            input[ne--] = '%';
            i--;
        }
        else
        {
            input[ne--] = input[i--];
        }
    }
    return input;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    char input[1000];
    cin.getline(input, 1000);

    char *newInput = newSpaces(input);

    cout << newInput << endl;
    return 0;
}