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
int rotatedSearch(vector<int> a, int key){
	int s = 0, e = a.size() - 1;
	while( s <= e){
		int mid = s + (e-s)/2;
		if( a[mid] == key){
			return mid;
		}
		if( a[mid]>=a[s]){
			if(key>=a[s] and key<=a[mid]){ e = mid - 1;}
			else{ s = mid + 1; }	
		}
		else {
			if(key>=a[mid] and key<=a[e]){s = mid + 1;}
			else{ e = mid - 1;}
		}
	}
	return -1;
}


int main(int argc, char const *argv[]){
		clock_t begin = clock();
		file_i_o();
		
		vector<int> arr = {7, 9, 10, 1, 2, 3, 4, 5, 6};
		int element = 9;

		cout<<rotatedSearch(arr, element); 

		#ifndef ONLINE_JUDGE
		clock_t end = clock();
		cout<<" \n\n Executed in : "<<double(end - begin)/CLOCKS_PER_SEC;
		#endif
		return 0;
	}