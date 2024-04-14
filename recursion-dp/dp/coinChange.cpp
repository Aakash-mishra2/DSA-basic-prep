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
vector<int> coins {1, 3, 7, 10};
// 
// int coinsChange(vector<int> coins, int val){
    
//     vector<int> dp(val+1, 100000);
//     dp[0] = 0;
//     for(int i = 1; i<= val; i++){
//         for( auto ele : coins ){
//             if( i - ele >= 0 ){
//                 dp[i] = min(dp[i], dp[i-ele] + 1);
//             }
//         }
//     }
//     return dp[val];
// }

// int main()
// {
//     vector<int> coins = {1, 3, 7, 10 };
//     int val = 15;
    
//     cout<<coinsChange(coins, val);
    
//     return 0;
// }
//
int coinsChange_BU(int n){
	vector<int> dp(n+1, 0);
	dp[0] = 0;
	for(int i = 1; i<= n; i++){
		for(int j =  0; j<=coins.size(); j++){
			if(i-coins[j]>=0){
				dp[i] = max(dp[i], 1 + dp[i-coins[j]]);
			}
		}
	}
	return dp[n];
}
int coinsChangeREC(int n){
	if(n == 0){ return 0; }
	if(n<0){ return 0; }
	int ans = INT_MAX;
	for(int i = 0; i<4; i++){
	 ans = min(ans, coinsChangeREC(n-coins[i])) + 1;
	}
	return ans;
}
// int coinsChange_TD(int n, int* dp2){
// 	if(n == 0){ return 0; }
// 	if(n<0){ return 0; }

// 	if(dp2[n] != 0){ return dp2[n]; }

// 	for(int i = 0; i<coins.size(); i++){
// 		ans = min(ans, coinsChangeREC(n-coins[i], dp2)) + 1;
	
// 	}
// 	return dp[2] = ans;
// }

int main(int argc, char const *argv[]){
		clock_t begin = clock();
		file_i_o();
		int n;
		cin>>n;
		

		cout<< coinsChange_BU(n);
		
		#ifndef ONLINE_JUDGE
		clock_t end = clock();
		cout<<" \n\n Executed in : "<<double(end - begin)/CLOCKS_PER_SEC;
		#endif
		return 0;
	}
