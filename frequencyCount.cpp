#include<bits/stdc++.h>
using namespace std;
void file_i_o(){
	ios_base::sync_with_stdio;
	cin.tie(0);
	cout.tie(0);
	#ifndef	ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
}
int frequencyCount(vector<int>arr, int key){
	int focc = -1, locc = -1;
	int s = 0, e = arr.size()-1;
	while( s <= e){
		int mid = (s + e)/2;
		if(arr[mid]==key){ focc = mid; e = mid - 1;}
		else if(arr[mid]<key){ s = mid + 1;}
		else e = mid - 1;
	}
	s = 0, e = arr.size()-1;
	while(s<=e){
		int mid = (s + e)/2;
		if(arr[mid]==key){locc = mid; s = mid + 1;}
		else if(arr[mid]>key){ e = mid - 1;}
		else s = mid + 1;
	}
	return (locc - focc + 1);
}
int main(){
	file_i_o();
	vector<int> arr {1, 2, 2, 2, 3, 3, 3, 3, 3, 4, 4, 6};
	cout<<frequencyCount(arr, 3);
	return 0;
}