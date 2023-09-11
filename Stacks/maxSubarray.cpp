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
/*
N = 9
arr = {1 2 3 1 4 5 2 3 6}
k = 3
3 3 4 5 5 5 6
*/
void maxSubArray(vector<int> a, int k){
    int i = 0;
    deque<int> Q;
    //process first k elements : find highest index 

    for( i = 0; i<k; i++){
        while(!Q.empty() and a[Q.front()] < a[i]){
            Q.pop_front();
        }
        Q.push_back(i);
    }
    //printing highest among first k elements
    cout<<a[Q.front()]<<" ";

    //process rest of elements
    for(; i<a.size(); i++){
        //remove elements from left when index lies outside current window
        while(!Q.empty() and Q.front() <= i-k){
            Q.pop_front();
        }

        //when greater element comes
        while(!Q.empty() and a[Q.back()] < a[i]){
            Q.pop_back();
        }
        Q.push_back(i);
        cout<<a[Q.front()]<<" ";
    }
}
int main(){

    vector<int>arr = {1, 2, 3, 1, 4, 5, 2, 3, 6};
    int K = 3;
    maxSubArray(arr, K);
    return 0;
}
