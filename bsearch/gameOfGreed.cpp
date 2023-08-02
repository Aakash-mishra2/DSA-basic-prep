#include<bits/stdc++.h>
using namespace std;

bool possibleToDivAmongK(vector<int>coins, int K, int limit){
	int partitions = 0, currentChildCoinsValue = 0;
	for( int i = 0; i<coins.size(); i++){
		if( currentChildCoinsValue + coins[i] >= limit){
			partitions += 1;
			currentChildCoinsValue = 0;
		}
		else currentChildCoinsValue += coins[i];
	}
	return partitions >= K;
}
//1 12 13 14 20 22 10 8 --- 3
//1 12 13 14 20 22 10 800 200 500 20000 --- 7
//1 12 13 14 20 22 10 800 200 500 20000 --- 5

int gameOfGreed(vector<int>coins, int K)	{
	int ans = 0, s = coins[0], e = 0; for( auto i: coins){ e += i; }
	while( s<= e){
		int mid = (s+e)/2;
		if(possibleToDivAmongK(coins,K,mid)){
			ans = mid; s= mid + 1;
		}
		else e = mid - 1;
	}
	return ans;
}
int main(){
	freopen("output.txt", "w", stdout);
	vector<int> coins = {1, 2, 3, 4};
	int K = 3;
	cout<<gameOfGreed(coins, K);
}