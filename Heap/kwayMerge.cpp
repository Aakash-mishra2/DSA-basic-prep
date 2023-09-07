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
vector<int> mergeKsorted(vector<vector<int>> &arr)
{
    vector<int> answer;
   priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>> > s;
   int k = arr.size();
   for(int k = 0; k<arr.size(); k++){
        s.push({arr[k][0], 0, k});
   }
    while(!s.empty()){
        auto temp = s.top();
        s.pop();
        int elem = temp.at(0);
        int ind = temp.at(1);
        int arr_ind = temp.at(2);

        if(ind == arr[arr_ind].size()){ continue; }

        answer.push_back(elem);
        s.push({arr[arr_ind][ind+1], ind+1, arr_ind});
    }
    return answer;
}

int main()
{
    file_io();
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
