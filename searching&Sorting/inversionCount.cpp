#include <bits/stdc++.h>
    using namespace std;
    
    int merge (vector<int> vec, int s, int e){
        int count = 0;
        int i = s;
        int mid = (s + e)/2;
        int j = mid + 1;
        vector<int> temp;
        
        while(i <= mid && j<= e){
            if(vec[i] < vec[j]){
                temp.push_back(vec[i]);
                i++;
            }
            
            else {
                count += (mid - i + 1);
                temp.push_back(vec[j]);
                j++;
            }
        }
        
        while(i<=mid){
            temp.push_back(vec[i++]);
        }
        while(j <= e){
            temp.push_back(vec[j++]);
        }
        
        //copy to original array
        // int k = 0;
        // for(int idx = s; idx <= e; idx++){
        //     vec[idx] = temp[k++];
        // }
        return count;
    }
    
    int invCount(vector<int>& arr, int s, int e){
        if( s>=e) return 0;
        
        int mid = (s + e)/2;
        int c1 = invCount(arr, s, mid);
        int c2 = invCount(arr, mid+1, e);
        int c3 = merge(arr, s, e);
        
        return c1 + c2 + c3;
    }
    
    int main()
    {
       vector<int> arr = {0, 5, 2, 3, 1};
       int n = arr.size();
       cout<<invCount(arr, 0, n-1);
    
        return 0;
    }
