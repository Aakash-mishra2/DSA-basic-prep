
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

string unique_substring(string input){
	unordered_map<char, int> M;
	int start_idx = 0;
	int i = 0, j = 0, max_window = 0, window_length = 0;
	while( j < input.length()){
		char ch = input[j];
		//check last occurence of every character - should be before starting of current window
		//if not close window start new from last occurence + 1;
		if(M.count(ch) and M[ch] >= i){
			i = M[ch] + 1;
			window_length = j - i ;
		}
		M[ch] = j; j++; window_length++;
		if(window_length > max_window){ max_window = window_length; start_idx = i;}
	}
	return input.substr(start_idx, max_window);
}

int main(int argc, char const *argv[]){
		clock_t begin = clock();
		file_i_o();

		string input;
		cin>>input;
		cout<< unique_substring(input);

		#ifndef ONLINE_JUDGE
		clock_t end = clock();
		cout<<" \n\n Executed in : "<<double(end - begin)/CLOCKS_PER_SEC;
		#endif
		return 0;
	}