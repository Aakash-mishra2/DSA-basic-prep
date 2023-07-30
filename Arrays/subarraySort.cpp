#include<bits/stdc++.h>
using namespace std;

void file_i_o(){
	ios_base::sync_with_stdio;
	cout.tie(0); cin.tie(0);
	#ifndef ONLINE_JUDGE
		freopen("../sliding-window/input.txt","r",stdin);
		freopen("../sliding-window/output.txt","w",stdout);
	#endif
}

bool outOfOrder(vector<int>arr, int i){
int x = arr[i];
	if(i==0) return x > arr[1];
	if(i==arr.size()-1) return x < arr[i-1];
	return (x > arr[i+1] or x < arr[i-1]);
}

pair <int, int> subArraySort(vector<int> arr){
	int i = 0, _smallest = INT_MAX, _largest = INT_MIN;
	while(i<arr.size()){
		if(outOfOrder(arr, i)){
			if(arr[i]<_smallest){_smallest = arr[i];}
			if(arr[i]>_largest){_largest = arr[i];}
		}
		i++;
	}
	if(_smallest == INT_MAX) return {-1, -1};
	int left = 0, right = arr.size()-1;
	while(_smallest >= arr[left])left++;
	while(_largest <= arr[right])right--;
	return make_pair(left, right);
}
int main(){
	file_i_o();
	vector<int> arr = {1, 2, 3, 4, 5, 6, 8, 6, 7, 9, 10, 11};
	auto ans = subArraySort(arr);
	cout<<"Required subarray is b/w indeces "<<ans.first<<" and "<<ans.second<<endl;
	return 0;
}