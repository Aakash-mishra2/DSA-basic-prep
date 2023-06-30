#include <bits/stdc++.h>
using namespace std;

string keypad[] = {"", "", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"};

void printKeypadOutput(string input, string output, int i = 0)
{
    if (i == input.length())
    {
        cout << output << endl;
        return;
    }

    int index = input[i] - '0';
    for (int z = 0; z < keypad[index].length(); z++)
    {
        printKeypadOutput(input, output + keypad[index].at(z), i + 1);
    }
}
int main()
{
    string input;
    cin >> input;
    string output;
    printKeypadOutput(input, output);

    return 0;
}