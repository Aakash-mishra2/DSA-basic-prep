#include<bits/stdc++.h>
using namespace std;

int min_Swaps(vector<int>arr){
	int ans = 0;
	vector<pair<int, int>> vec = {};
	for(int i = 0; i<arr.size(); i++){
		vec.push_back(make_pair(arr[i], i));
	}
	for( auto i: vec){cout<<i.first<<" "<<i.second<<endl; }
	sort(arr.begin(), arr.end());
	vector<bool> visited(arr.size(), false);
	for(int i = 0; i<arr.size(); i++){
		cout<<vec[i].first<<" "<<vec[i].second<<endl;
		if(visited[i]==true or vec[i].second==i){
			cout<<i<<endl;	continue;
		}
		int currentIndex = i, thisCycle = 0;//cycle nodes count
		while(!visited[currentIndex]){
			cout<<arr[currentIndex]<<endl;
			visited[currentIndex] = true;
			currentIndex = vec[currentIndex].second;
			thisCycle++;
		}
		cout<<thisCycle;
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