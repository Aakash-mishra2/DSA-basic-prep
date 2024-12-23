#include <bits/stdc++.h>
using namespace std;

// unique - substrings
int minSwaps(vector<int> arr){
    //know actual positions store current indices
    int n = arr.size();
    pair<int, int> ap[n];
    for(int i = 0; i<n; i++){
        ap[i].first = arr[i];
        ap[i].second = i;
    }
    //sorting
    sort(ap, ap+n);
    vector<bool> visited(n, false);
    int ans = 0;
    for(int i=0; i<n; i++){
        //if element is visited or element is in right position
        int old_position = ap[i].second;
        if(visited[i]== true or old_position == i){
            continue;
        }

        //visiting the element (index) for first time;
        int node = i, cycle = 0;
        while(!visited[node]){
            visited[node] = true;
            int next_node = ap[node].second;
            node = next_node;
            cycle += 1;
        }
        ans += (cycle - 1);
    }
    return ans;
}

int main()
{
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    vector<int> arr = {5, 4, 3, 2, 1};
    cout << minimum_swaps(arr) << endl;
    return 0;
}
