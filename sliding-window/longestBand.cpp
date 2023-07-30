
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

int longestBand(vector<int> arr){
	unordered_set<int> S; int bandLength=0, longestBand=0;
	for( auto i: arr) S.insert(i);
	for(auto ele : S){
		if(S.find(ele-1) != S.end()){ continue; }
		else {	bandLength=1;
		while(S.find(ele+1) != S.end()){ bandLength++; ele+=1;}
		}
		if(bandLength > longestBand)longestBand = bandLength;
	}
	return longestBand;
}

int main(int argc, char const *argv[]){
		clock_t begin = clock();
		file_i_o();

		vi nums{1, 9, 16, 0, 18, 5, 2, 14, 15, 10, 17, 12, 13};
		cout<< longestBand(nums);

		#ifndef ONLINE_JUDGE
		clock_t end = clock();
		cout<<" \n\n Executed in : "<<double(end - begin)/CLOCKS_PER_SEC;
		#endif
		return 0;
	}