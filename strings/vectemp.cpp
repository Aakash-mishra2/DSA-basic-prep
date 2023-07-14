#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v1{5, 6, 7}, v2{4, 3, 1};
    vector<int> v3 = v2;
    for (auto i : v3)
    {
        cout << i;
    }
}