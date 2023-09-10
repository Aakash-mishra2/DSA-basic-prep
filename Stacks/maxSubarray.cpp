#include<bits/stdc++.h>
using namespace std;

void maxSubArray(vector<int> a, int k){
    deque<int> Q(k);
    //process first k elements
    int i;
    for(i = 0; i<k; i++ ){
        while(!Q.empty() && a[i] > a[Q.back()]){
            Q.pop_back();
        }
        Q.push_back(i);
    }

    //process rest of elements
    for( ; i<a.size(); i++){

        //remove elements from left when an index lies outside current window.
        while(!Q.empty() and Q.front() <= i-k){
            Q.pop_front();
        }
        //when greater element comes 
        while(!Q.empty() and a[i]>a[Q.back()]){
            Q.pop_back();
        }
        Q.push_back(i);
    }
}
int main(){
    vector<int>arr = {1, 2, 3, 1, 4, 5, 2, 3, 5};
    int K = 3;
    maxSubArray(arr, K);
    return 0;
}
