/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

void min_pair(vector<int> a1, vector<int> a2){
    
    //sort any one array
    sort(a1.begin(), a1.end());
    int p1, p2, diff = 1000000;
    //iterate over 1 array and look for closest elements in sorted array
    for( int x : a2){
        //lower_bound(element) returns index of first element in array with value >= than the passed argument 
        auto lb = lower_bound(a1.begin(), a1.end(), x) - a1.begin();
        
        //left
        if( lb>=1 and x-a1[lb-1] < diff ){
            diff = x - a1[lb -1];
            p1 = x;
            p2 = a1[lb-1];
        }
        // greater / right
        if( lb != a1.size() and a1[lb]-x < diff){
            diff = a1[lb] -x;
            p1 = x;
            p2 = a1[lb];
        }
    }
    cout <<" Min pair "<<p1<<" and "<<p2;
    return;
    
}

int main(){
    vector<int> a1 = {-1, 5, 10, 20, 3 };
    vector<int> a2 = { 26, 134, 135, 15, 17 };
    
    min_pair(a1 ,a2);
    
    return 0;
    
}
