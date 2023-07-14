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
        if (S.find(input[i]) == S.end())
        {
            swap(input[i], input[index]);
            allUniquePermutations(input, index + 1);
            swap(input[i], input[index]);
        }
    }
}

int main()
{
    string input;
    cin >> input;
    cout << "All Permutations resultant :-  " << endl;
    allUniquePermutations(input);

    return 0;
}