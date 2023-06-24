#include <bits/stdc++.h>
using namespace std;

string keypad[] = {"", "", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"};

void printKeypadOutput(string input, string output, int i = 0)
{
    if (input[i] == '\0')
    {
        cout << output << endl;
        return;
    }

    int index = input[i] - '0';
    if (index == 0 or index == 1)
    {
        printKeypadOutput(input, output, i + 1);
    }

    for (int j = 0; j < keypad[index].length(); j++)
    {

        char ch = keypad[index][j];
        printKeypadOutput(input, output + ch, i + 1);
    }
    return;
}
int main()
{
    string input;
    cin >> input;
    string output;
    printKeypadOutput(input, output);

    return 0;
}