#include <bits/stdc++.h>
using namespace std;

int rotatedSearch ( vector<int> arr, int key ){
    int s = 0, e = arr.size() - 1;
    
    while( s <= e ){
        int mid = (s + e)/2;
        if( arr[mid] == key){
            return mid;
        }
        if( arr[s] <= arr[mid] ){
            if( arr[s] <= key and key<= arr[mid] ){
                e = mid - 1;
            }
            else s = mid + 1;
        }
        else {
            if( arr[mid] <= key and key<= arr[e]){
                s = mid + 1;
            }
            else {
                e = mid - 1;
            }
        }
    }
    return -1;
}

int main() {
    int t; cin>>t;
    vector<int> vec = { 7, 9, 10, 1, 2, 3, 4, 5, 6 };
    while( t-- ){
        int key; cin>>key;
        cout<<" Element found at :"<<rotatedSearch(vec, key);
    }
}
