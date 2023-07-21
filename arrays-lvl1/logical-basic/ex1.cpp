#include <iostream>
#include <stdio.h>
using namespace std;

void manipArray(int *array, int x)
{
    array[2] = x;
}

int main()
{
    int arr[] = {34, 4, 14, 2, 45};
    cout << arr << " " << *(arr) << " " << &arr << endl;
    cout << arr[2] << endl;
    manipArray(arr, 57);
    cout << arr[2] << endl;
    char st1[100];
    gets(st1);
    puts(st1);
    string st2;
    gets(const_cast<char *>(st2.c_str()));
    puts(const_cast<char *>(st2.c_str()));
    return 0;
}