#include <bits/stdc++.h>
using namespace std;

void allUniquePermutations(string input, int index = 0)
{
    if (index == input.length())
    {
        cout << input << endl;
        return;
    }
    unordered_set<char> S;

    for (int i = index; i < input.length(); i++)
    {
        if (S.find(input[i]) != S.end())
        {
            continue;
        }
        S.insert(input[i]);

        swap(input[index], input[i]);
        allUniquePermutations(input, index + 1);
        swap(input[index], input[i]);
    }
}

int main()
{
    string input;
    cin >> input;

    allUniquePermutations(input);

    return 0;
}