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
void stockSpan(int prices[], int n, int span[]){
    stack<int> s;
    s.push(0);  // indices of the stack;
    span[0] = 1;

    //loop for rest of days; -->O(1);
    for( int i = 1; i<=n-1; i++){
        int currentPrice = prices[i];
        //topmost element higher than current price

        while(!s.empty() and prices[s.top()] <= currentPrice){
            s.pop();
        }
        // either stack empty or element at top higher than current price

        if(s.empty()){ span[i] = i+1;}
        else if(!s.empty()) { 
        int prevHighestAtIndex = s.top();
        span[i] = i - prevHighestAtIndex;
        }
        //push current element in stack
        s.push(i);
    }
}

int main(){
    file_io();
    int prices[] = {100, 80, 60, 70, 60, 75, 85};
    int n = sizeof(prices)/sizeof(int);
    int span [100000] = {0};

    stockSpan(prices, n, span);
    for(int i = 0; i<n; i++){
        cout<<span[i]<<" ";
    }
    return 0;
}   
