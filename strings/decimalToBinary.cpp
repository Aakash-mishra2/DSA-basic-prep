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
// int decimalToBinary(int x)
// {
//     int ans = 0, pow = 1;
//     while(x>0){
//         ans += (x%2)*pow;
//         pow *= 10;
//         x /= 2;
//     }
//     return ans;
// }
int main()
{
    int n;
    int ans = 0, power = 0;
    cin >> n;
    cout << decimalToBinary(n);
    return 0;
}
