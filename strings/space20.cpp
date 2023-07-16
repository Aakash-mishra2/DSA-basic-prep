#include <bits/stdc++.h>
using namespace std;

string space20(char *input)
{
    int count = 0, i = 0;
    for (; input[i] != '\0'; i++)
    {
        if (input[i] == ' ')
        {
            count++;
        }
    }
    int j = i + 2 * count;
    while (i < j)
    {
        if (input[i] != ' ')
        {
            input[j] = input[i];
            i--;
            j--;
        }
        else
        {
            input[j--] = '0';
            input[j--] = '2';
            input[j--] = '%';
            i--;
        }
    }
    return input;
}

int main()
{
    char input[1000];
    cin.getline(input, 1000);
    space20(input);
    cout << input << endl;
    return 0;
}