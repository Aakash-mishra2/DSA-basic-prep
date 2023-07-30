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
int rains(vector<int> arr){
	vector<int> leftArray(arr.size(), 0) , rightArray(arr.size(), 0);
	int max = INT_MIN;
	for(int i = 0; i < arr.size(); i++){
		if( arr[i] > max) max = arr[i];
		leftArray[i] = max;
	}
	max = INT_MIN;
	for(int i = arr.size()-1; i>= 0; i--){
		if( arr[i] > max) max = arr[i];
		rightArray[i] = max;
	}
	int answer = 0;
	for( int i = 0; i<arr.size(); i++){
		answer += min(leftArray[i], rightArray[i]) - arr[i];
	}
	return answer;
}
int main(){
	file_i_o();
	vector<int> arr {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
	cout<<rains(arr);
	return 0;
}