#include <iostream>
#include <cstring>

using namespace std;

int sparseSearch(string arr[], string key, int n)
{
    int s = 0;
    int e = n - 1;
    while (s <= e)
    {
        int mid = (s + e) / 2;
        int mid_left = mid - 1;
        int mid_right = mid + 1;
        if (arr[mid] == "")
        {

            while (1)
            {
                if (mid_left < s and mid_right > e)
                {
                    return -1;
                }
                else if (mid_left >= s and arr[mid_left] != "")
                {
                    mid = mid_left;
                    break;
                }
                else if (mid_right <= e and arr[mid_right] != "")
                {
                    mid = mid_right;
                    break;
                }
                mid_left--;
                mid_right++;
            }
        }
        else if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] > key)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return -1;
}

int main()
{
    int n = 12;
    string arr[] = {"air", "", "", "bat", "", "", "car", "cat", "", "", "dog", ""};
    string find;
    cin >> find;
    cout << sparseSearch(arr, find, 12);
    return 0;
}