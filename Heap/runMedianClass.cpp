#include<bits/stdc++.h>
using namespace std;

//Note : Don't Edit the class name and given methods. 
// Add helper methods or any properties if needed.
class MedianHandler{
public:
    float median;
    priority_queue<int> leftHeap;                             // maxHeap
    priority_queue<int, vector<int>, greater<int>> rightHeap; // minHeap
    
    void push(int number){
        //Complete this method to update median after every insertion 
        leftHeap.push(number);
        median = number;
        
        if(leftHeap.size() > rightHeap.size()){
            if( number < getMedian()){
                rightHeap.push(leftHeap.top());
                leftHeap.pop();
                leftHeap.push(number);
            }
            else{
                rightHeap.push(number);
            }
            median = (leftHeap.top() + rightHeap.top())/2;
        }
        else if( leftHeap.size() == rightHeap.size()){
            if( number < getMedian()){
                leftHeap.push(number);
                median = leftHeap.top();
            }
            else{
                rightHeap.push(number);
                median = rightHeap.top();
            }
        }
        else {
            if(number < getMedian()){
                leftHeap.push(number);
            }
            else{
                leftHeap.push(rightHeap.top());
                rightHeap.pop();
                rightHeap.push(number);
            }
            median = (leftHeap.top() + rightHeap.top())/2;
        }
    }
    float getMedian(){
        //Complete this , Should return the median in O(1) time
        return median;
    }
};
