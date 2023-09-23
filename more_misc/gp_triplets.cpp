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

int tripletsGP(vector<int> &arr, int n, int R)
{
    int answer = 0;
    unordered_map<int, int> leftA, rightA;
    for( auto x : arr){
        rightA[x]++;
    }
    for(int i = 0; i<n; i++){

        if(i == 0 or i == n-1){
            rightA[arr[i]]--;
            leftA[arr[i]]++;
            continue;
        }
        else{
        rightA[arr[i]]--;
        answer += (leftA[arr[i]/R] * rightA[arr[i]*R]);
        leftA[arr[i]]++;

        }
    }
    return answer;
}

int main()
{
    file_io();
    int n;
    cin >> n;
    int commRatio;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cin >> commRatio;
    cout << "no. of GP triplets are : " << tripletsGP(arr, n, commRatio);

    return 0;
}
