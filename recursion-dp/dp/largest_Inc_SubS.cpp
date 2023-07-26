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
int increasingSubsequence(vector<int> number){
	int N = number.size();
	vector<int> dp(N, 1);
	for(int i = 1; i<=N; i++){
		for( int j=0; j<i; j++){
			if(number[j]<=number[i]){
			dp[i] = max(dp[i], 1 + dp[j]);
			}
		}
	}
	int max=0;
	for( auto i : dp){
		if(i > max){ max = i;}
	}
	return max;
}

int main(int argc, char const *argv[]){
		clock_t begin = clock();
		file_i_o();
		int n = 0;
		
		vector<int> number {50, 4, 10, 8, 30, 100, 9};
		cout<< increasingSubsequence(number);
		
		#ifndef ONLINE_JUDGE
		clock_t end = clock();
		cout<<" \n\n Executed in : "<<double(end - begin)/CLOCKS_PER_SEC;
		#endif
		return 0;
	}