#include <bits/stdc++.h>
using namespace std;

string longest_band(vector<int> arr, int i = 0)
{
    
}
string extractStringAtKey(string st, int key)
{
    char *token = strtok((char *)st.c_str(), "-");
    while (key > 1)
    {
        token = strtok(NULL, "-");
    }
    return token;
}
int main()
{
    vector<int> arr = {1, 9, 3, 0, 18, 5, 2, 4, 10, 7, 12, 6};

    cout << longest_band(arr);

    return 0;
}