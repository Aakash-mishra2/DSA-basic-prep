#include<bits/stdc++.h>
using namespace std;
void file_io()
{
    ios_base::sync_with_stdio;
    cout.tie(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int tripletsGP(vector<int>& arr, int n, int R){
    unordered_map<int, int> left, right;
    for( int i = 0; i<n; i++){
        right[arr[i]]++;
    }
    int answer = 0;
    for( int i = 0; i<n; i++){
        if( i ==0 or i== n-1){ 
            left[arr[i]]++; right[arr[i]]--;
            continue;
            }
        else{
            right[arr[i]]--;
            int a1 = arr[i]/R;
            int a2 = arr[i]*R;
            
            answer += (left[a1])*(right[a2]);
            left[arr[i]]++;
        }
    }
    return answer;
}
/*
6
1 16 4 16 64 16
4
*/
int main(){
    file_io();
    int n;
    cin>>n;
    int commRatio;
    vector<int> arr(n);
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    cin>>commRatio;
    cout<<"no. of GP triplets are : "<<tripletsGP(arr, n, commRatio);

    return 0;
}
