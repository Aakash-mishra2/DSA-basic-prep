#include<bits/stdc++.h>
using namespace std;

void file_i_o(){
	ios_base::sync_with_stdio;
	cout.tie(0); cin.tie(0);
	#ifndef ONLINE_JUDGE
	 freopen("../sliding-window/input.txt", "r", stdin);
	 freopen("../sliding-window/output.txt", "w", stdout);
	#endif
}

int mountains(vector<int> arr){
	int answer = 0;
	for(int i = 1; i<=arr.size()-2;){
		if(arr[i]>arr[i-1] and arr[i]>arr[i+1]){
			int thisMntnSize = 3, l = i-1; i+= 1;
			while(arr[l-1] < arr[l]) {l--; thisMntnSize++;}
			while(arr[i]>arr[i+1]){ i++; thisMntnSize++;}
			answer = max(answer, thisMntnSize);
		}
		i++;
	}
	return answer;
}

int main(){
	file_i_o();
	vector<int> arr = {5, 6, 1, 2, 3, 4, 5, 4, 3, 2, 0, 1, 2, 3, -2, 4};
	cout<<mountains(arr);
	return 0;
}