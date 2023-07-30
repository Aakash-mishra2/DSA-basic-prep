#include<bits/stdc++.h>
using namespace std;

int min_Swaps(vector<int>arr){
	int ans = 0;
	vector<pair<int, int>> vec;
	for(int i = 0; i<arr.size(); i++){
		vec.push_back(make_pair(arr[i], i));
	}
	sort(vec.begin(), vec.end());
	vector<bool> visited(arr.size(), false);
	for(int i = 0; i<arr.size(); i++){
		if(visited[i]==true or vec[i].second==i){
			continue;
		}
		int currentIndex = i, thisCycle = 0;//cycle nodes count
		while(!visited[currentIndex]){
			visited[currentIndex] = true;
			currentIndex = vec[currentIndex].second;
			thisCycle++;
		}
		ans += thisCycle-1;
	}
	return ans;
}
void file_i_o(){
	ios_base::sync_with_stdio;
	cout.tie(0); cin.tie(0);
	#ifndef ONLINE_JUDGE
	 freopen("../sliding-window/input.txt", "r", stdin);
	 freopen("../sliding-window/output.txt", "w", stdout);
	#endif
}
int main(){
	file_i_o();
	vector<int> arr = {5, 4, 3, 2, 1};
	cout<<min_Swaps(arr);
	return 0;
}
