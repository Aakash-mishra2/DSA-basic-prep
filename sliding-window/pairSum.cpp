//https://leetcode.com/problems/longest-mountain-in-array/submissions/956480057/
//https://leetcode.com/problems/trapping-rain-water/
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<pair<int, int>> vii;
#define vi			vector<int>
#define vll 		vector<ll>
#define vs 			vector<string>
#define pii 		pair<long, long>
#define ff 			first
#define ss 			second
#define mid(l,r) 	(l+ (l-r)/2)
#define pb 			push_back
#define endl 		"\n"
#define mod 		1e10 + 7
#define inf 		10e8 + 1
#define mp 			make_pair
#define all(n) 		n.begin(),n.end()
#define loop(i, a, b) for(int i =(a); i<=(b); i++)
#define looprev(i, a, b) for(int i =(a); i>=(b); i--)

void file_i_o(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
}

pair<int,int> pairSum(vector<int>arr, int sum){
	unordered_set<int> S;
	vector<int> result;
	loop(i, 0, arr.size()-1){
		int comp = sum - arr[i];
		if(S.find(comp) != S.end()){ 
			return make_pair(arr[i], comp);
		}
		//insert the current no inside set .
		//dont do it at beginning. otherwise[2,2] case possible.
		S.insert(arr[i]);
	}
	return {};
}

int main(int argc, char const *argv[]){
		clock_t begin = clock();
		file_i_o();

		vi arr{10, 5, 2, 3, -6, 9, 11};
		int S = 4;

		auto p = pairSum(arr, S);
		if(p.size() == 0){
			cout<<" No Such Pair. ";
		}
		else{
			p.first<<" "<<p.second<<endl;
		}

		#ifndef ONLINE_JUDGE
		clock_t end = clock();
		cout<<" \n\n Executed in : "<<double(end - begin)/CLOCKS_PER_SEC;
		#endif
		return 0;
	}