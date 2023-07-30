//find smallest substring inside big string that contains all the characters of small string.

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
//full hashmap of pattern
//maintain hasmap of window
//at every step check whether pattern lies inside current window.
//moment pattern lies start removing unneccessary elements from left end.

string String_window(string s, string p){
	char fPat[256], fWindow[256];
	for(int i = 0; i<p.length(); i++){fPat[p[i]]++;}
	int i = 0, j = 0, start_idx = -1, count = 0, minimumWindow = INT_MAX, window_size = 0;
	for(int j = 0; j<s.length(); j++){
		fWindow[s[j]]++;
		if(fPat[s[j]]!= 0 and fWindow[s[j]]<=fPat[s[j]]) {count += 1;}
		if(count == p.length()){//contract unneccesary nodes
			while(fWindow[s[i]] > fPat[s[i]] or fPat[s[i]]==0){fWindow[s[i]]--; i++;}
			window_size = j - i + 1;
			if(window_size < minimumWindow){ minimumWindow = window_size; start_idx = i;}
		}
	}
	if(start_idx==-1){ return "No window found. "; }
	return s.substr(start_idx, minimumWindow);
}

int main(int argc, char const *argv[]){
		clock_t begin = clock();
		file_i_o();
		string s, p;
		cin>>s>>p;
		cout<<String_window(s, p)<<endl;

		#ifndef ONLINE_JUDGE
		clock_t end = clock();
		cout<<" \n\n Executed in : "<<double(end - begin)/CLOCKS_PER_SEC;
		#endif
		return 0;
	}