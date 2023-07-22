#include <iostream>
using namespace std;

int main()
{
    int a, b;
    cin >> a;
    cin >> b;
    a = a + b;
    b = b - a;
    a = a + b;
    b = -b;

    cout << a << " " << b << endl;
    return 0;
}