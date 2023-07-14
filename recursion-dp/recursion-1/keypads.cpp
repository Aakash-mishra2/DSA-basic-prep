#include <bits/stdc++.h>
using namespace std;

string keypad[] = {"", "", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"};

void printKeypadOutput(string input, string output, int i = 0)
{
    if (i == input.size())
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
        printKeypadOutput(input, output + keypad[index].at(j), i + 1);
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