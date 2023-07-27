#include<bits/stdc++.h>
using namespace std;
void file_i_o(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
}
template<typename T>
T root_Binary(T n, int start = 0){
	int end = n;
	int mid = start + (end - start)/2;
	T ans = -1;
	while( start <= end ){

		long long j = mid * mid;
		if( j == n) return mid;
		if(j < n){ ans = mid; start = mid + 1; }
		else{ end = mid - 1; }
		
		mid = start  + (end - start)/2;
	}
	return ans;
}
double precise_root( n, int precision){
	double Answer = (double)root_Binary<double>(n);
	double fraction = 1;
	for(double i = 1; i<=precision; i++){
		fraction /= 10;
		for( double j = Answer; j*j<=n; j+=fraction){ Answer = j;}
	}
return Answer;
}
int main(){
	//cout<<" Enter number : ";
	//int n; cin>>n;
	file_i_o();
	double n = 17;
	cout<<" Square root is : "<<static_cast<double>(precise_root(n, 3));
	return 0;
}
