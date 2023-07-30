//deal with negative numbers in array.
//gfg sub array with sum 0 - unordered map, cs = 0 -true or cs = repeats -true
//largest/smallest window/subarray with sum 0/k;
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
int main(int argc, char const *argv[]){
		clock_t begin = clock();
		file_i_o();
		
		int n, k;
		cin>>n>>k;
		vi arr(n,0);
		loop(i,0,n-1){ cin>>arr[i]; }

		int current_sum = 0, j = 0, i= 0;
		while(j<arr.size()){
			current_sum += arr[j];
			while(current_sum>k and i<j){current_sum -= arr[i]; i++;}
			if(current_sum == k) cout<<i<<" "<<j<<" "<<endl;
			j++;
		}

		#ifndef ONLINE_JUDGE
		clock_t end = clock();
		cout<<" \n\n Executed in : "<<double(end - begin)/CLOCKS_PER_SEC;
		#endif
		return 0;
	}