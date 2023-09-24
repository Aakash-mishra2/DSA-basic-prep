#include<bits/stdc++.h>
using namespace std;

void file_io(){
    ios_base::sync_with_stdio;
    cout.tie(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("../MORE_miscc/input.txt", "r", stdin);
        freopen("../MORE_miscc/output.txt", "w", stdout);
    #endif
    }
inline namespace arrOrder{
    bool asc = true;
    bool desc = true;
}

bool isSorted(vector<int> arr,int n){
    if(n == 0){ return asc||desc; }
    
    if(asc == true) asc = (asc and arr[n] >= arr[n-1]);
    if(desc == true) desc = (desc and arr[n] <= arr[n-1]);

    return isSorted(arr, n-1);
}
int Bsearch(vector<int> arr,int key, int s, int e){
    if(s>e){ return -1; }
    else {
        int mid = s + (e-s)/2;
        if(arr[mid] == key){ return mid;}
        else if(key > arr[mid]){ 
            if(asc) s = mid + 1;
            if(desc) e = mid - 1; }
        else {
            if(asc) e = mid - 1;
            if(desc) s = mid + 1;
        }
    }
    return Bsearch(arr, key, s, e);
}
int main(){
    int ans = 0;
    vector<int> arr { -17, 4, 5, 10, 12, 14, 19};
    if(isSorted(arr, arr.size()-1) == true){
        int key; cin>>key;
        int s = 0; int e = arr.size()-1;
        ans = Bsearch(arr,key, s, e);
    }
    else{ cout<<" Array not sorted! "<<endl; return 0;}
    if(ans == -1){ cout<<"Key not found!"<<endl;}
    else cout<<"Key found at position "<<ans + 1<<endl;
    return 0;
}
