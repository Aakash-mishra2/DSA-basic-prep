#include <bits/stdc++.h>
using namespace std;

int longest_band(vector<int> arr, int i = 0)
{
    unordered_set<int> s;
    for( auto i : arr ){ s.insert(i); }
    int answer = 0;
    for( auto ele : s){
        int band_len = 1;
        if( s.find(ele-1) != s.end()){ continue; }
        else{
            while(s.find(ele+1)!=s.end()) {
                band_len += 1;
                ele += 1;
            }
            if( band_len > answer) answer = band_len;
        }
    }
    return answer;
}
int main()
{
    vector<int> arr = {1, 9, 3, 0, 18, 5, 2, 4, 10, 7, 12, 6};

    cout << longest_band(arr);

    return 0;
}
