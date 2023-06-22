#include <bits/stdc++.h>
using namespace std;

string stringWindow(string big, string small)
{
    char fsmall[256] = {0};
    char fwindow[256] = {0};
    int min_window = 0, window_length = 0, start_idx = -1;
    for (auto i : small)
    {
        fsmall[small[i]]++;
    }
    int i = 0, count = 0, start = 0;
    while (i < big.length())
    {
        // expand window till window has all char of pattern
        char ch = big[i];
        fwindow[ch]++;
        if (fsmall[ch] != 0 and fwindow[ch] <= fsmall[ch])
        {
            count++;
        }
        if (count == small.length())
        {
            while (fsmall[big[start]] == 0 or fwindow[big[start]] > fsmall[big[start]])
            {
                fwindow[big[start]]--;
                start++;
            }
            window_length = i - start + 1;
            if (window_length < min_window)
            {
                min_window = window_length;
                start_idx = start;
            }
        }
        if (start_idx == -1)
        {
            return "No window found";
        }
        i++;
    }
    return big.substr(start_idx, window_length);
}

int main()
{
    string big, small;
    cin >> big >> small;
    cout << stringWindow(big, small);
    return 0;
}