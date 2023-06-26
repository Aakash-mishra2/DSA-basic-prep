#include <bits/stdc++.h>
using namespace std;

int main()
{
    int num = 17;
    // cin >> num;
    unsigned long long int ans = 0;
    int count = 0;
    while (num != 0)
    {
        int rem = num % 2;
        long long int c = pow(10, count);
        ans += rem * c;
        num = num / 2;
        count++;
    }
    cout << ans;
    return 0;
}