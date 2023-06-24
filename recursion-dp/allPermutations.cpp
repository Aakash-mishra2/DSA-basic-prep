#include <bits/stdc++.h>
using namespace std;

void allPermutations(string input, int index = 0)
{

    if (index == input.length())
    {
        cout << input << endl;
    }

    for (int i = index; i < input.length(); i++)
    {
        swap(input[index], input[i]);
        allPermutations(input, i + 1);
        swap(input[index], input[i]);
    }
}

int main()
{
    string input;
    cin >> input;

    allPermutations(input);

    return 0;
}