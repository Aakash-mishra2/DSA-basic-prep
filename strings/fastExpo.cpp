#include <bits/stdc++.h>
using namespace std;
int decimalToBinary(int x)
{
    int ans = 0, power = 0;
    while (x > 0)
    {
        int rem = x % 2;
        ans = ans + rem * pow(10, power);
        power++;
        x = x >> 1;
    }
    return ans;
}
int fastExpo(int a, int b)
{
    int ans = 1;
    int bit;
    while (b > 0)
    {
        bit = b & 1;
        if (bit)
        {
            ans = ans * a;
        }
        a = a * a;
        b = b >> 1;
    }
    return ans;
}
int main()
{
    int n, k;
    cin >> n >> k;
    // decimal to binary k/ bits n multiply power
    cout << fastExpo(n, k);
    return 0;
}