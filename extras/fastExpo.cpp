#include <bits/stdc++.h>
using namespace std;

// Fast Exponentiation in log(n) time.

int fast_expo(int a, int n)
{
    int ans = 1;
    while (n > 0)
    {
        int last_bit = (n & 1);
        if (last_bit)
        {
            ans = ans * a;
        }
        a = a * a;
        n = n >> 1;
    }
    return ans;
}

int main()
{ // any number n can have at most log(n) bits.
    int a, n;
    cin >> a >> n;
    cout << fast_expo(a, n) << endl;
    return 0;
}