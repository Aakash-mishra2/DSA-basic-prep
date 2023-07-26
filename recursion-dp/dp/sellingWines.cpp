#include<bits/stdc++.h>
using namespace std;

int sellingWines(vector<int> wines){
	int N = wines.size();
	vector<vector<int>> dp(N+1, vector<int>(N+1, 0));
	for( int i = N-1; i>= 0; i--){
		for( int j = 0; j<=N-1; j++){
			int year = N - (j - i);
			if( i == j){
				dp[i][j] = wines[i]*year;
			}
			else if ( i < j){
				dp[i][j] = max(wines[i]*year + dp[i+1][j], wines[j]*year + dp[i][j-1]);
				cout<<dp[i][j]<<",";
			}
		}
		cout<<endl;
	}
	return dp[0][N-1];
}

int main(){
	vector<int> wines = {2, 3, 5, 1, 4};
	cout<<sellingWines(wines);
}