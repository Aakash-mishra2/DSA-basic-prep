//lc 4; median of sorted arrays: corner: empty error cases;
//https://leetcode.com/problems/median-of-two-sorted-arrays/description/

#include <bits/stdc++.h>
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
int main()
{
    file_io();
    priority_queue<int, vector<int>, greater<int>>rightHeap;
    priority_queue<int> leftHeap;

    int d; cin>>d;
        float median = d;
        leftHeap.push(d);
        cout<<median<<" ";
        cin>>d;

    while(d!= -1){

        if(leftHeap.size() == rightHeap.size()){ 
            if(d < median){    leftHeap.push(d); median = leftHeap.top(); }
            else {  rightHeap.push(d); median = rightHeap.top(); }
        }
        else if(leftHeap.size() > rightHeap.size()){
            if(d > median){ rightHeap.push(d); }
            else{
                rightHeap.push(leftHeap.top()); 
                leftHeap.pop();  leftHeap.push(d);
            }
            median = static_cast<float>(leftHeap.top() + rightHeap.top())/2;
        }
        else{   
            if( d < median){ leftHeap.push(d); }
            else{
                leftHeap.push(rightHeap.top());
                rightHeap.pop(); rightHeap.push(d);
            }
            median = static_cast<float>(leftHeap.top() + rightHeap.top())/2;
        }
        cout<<median<<" "; cin>>d;    
    }
}
