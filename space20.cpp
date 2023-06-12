// Given a string, write a function to replace all whitespaces with %20.
// write a fxn to replace all spaces in a string with '%20'. It is given that the string has sufficient
// space at the end to hold the additional characters.

#include <iostream>
using namespace std;

char *newSpaces(char *input)
{
    int count = 0;
    int i = 0;
    for (; input[i] != '\0'; i++)
    {
        if (input[i] == ' ')
            count++;
    }
    int j = i + 2 * count;
    while (j > i)
    {
        if (input[i] == ' ')
        {
            input[j--] = '0';
            input[j--] = '2';
            input[j--] = '%';
            i--;
        }
        else
        {
            input[j--] = input[i--];
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