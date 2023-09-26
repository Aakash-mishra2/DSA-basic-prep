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

vector<int> mergeKsorted(vector<vector<int>> &arr){
    int rows = arr.size();
    vector<int> ans;
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>> > heap;
    for(int i = 0; i<rows; i++){    
        heap.push({arr[i][0], 0, i}); 
    }
    while(!heap.empty()){
        auto temp = heap.top();
        heap.pop();
        int elem = temp.at(0);
        int ind = temp.at(1);
        int arr_ind = temp.at(2);

        if(ind == arr[arr_ind].size()){ continue;}

        heap.push({arr[arr_ind][ind+1], ind+1, arr_ind});
        ans.push_back(elem);
    }
    return ans;
}

int main()
{
   // file_io();
    vector<vector<int>> arr = {{10, 15, 20, 30},
                               {2, 5, 8, 14, 24},
                               {0, 11, 60, 90}};

    vector<int> ans = mergeKsorted(arr);

    for (auto x : ans)
    {
        cout << x << " ";
    }
    return 0;
}
