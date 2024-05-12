#include <bits/stdc++.h>
using namespace std;
void file_i_o()
{
    ios_base::sync_with_stdio;
    cout.tie(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
int main()
{
    file_i_o();
    int n;
    cin >> n;
    vector<int> array(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }
    int a = 0, b = 0;
    while (b < array.size())
    {
        if (array[b] == 0)
        {
            b++;
        }
        else
        {
            array[a] = array[b];
            array[b] = 0;
            a++;
            b++;
        }
    }
    for (auto i : array)
    {
        cout << " " << i;
    }
    cout << endl;
    return 0;
}
