#include<bits/stdc++.h>
using namespace std;
void file_i_o(){
	ios_base::sync_with_stdio;
	cin.tie(0);
	cout.tie(0);
	#ifndef	ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
}
int frequencyCount(vector<int>arr, int key){
	int focc = -1, locc = -1;
	int s = 0, e = arr.size()-1;
	while( s <= e){
		int mid = (s + e)/2;
		if(arr[mid]==key){ focc = mid; e = mid - 1;}
		else if(arr[mid]<key){ s = mid + 1;}
		else e = mid - 1;
	}
	s = 0, e = arr.size()-1;
	while(s<=e){
		int mid = (s + e)/2;
		if(arr[mid]==key){locc = mid; s = mid + 1;}
		else if(arr[mid]>key){ e = mid - 1;}
		else s = mid + 1;
	}
	return (locc - focc + 1);
}
/*
#include<bits/stdc++.h>
using namespace std; 
void file_i_o()
{
ios_base::sync_with_stdio;
  cout.tie(0);
cin.tie(0);
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt","w", stdout);
#endif
}
pair<int, int> first_and_last_occ(vector<int> vec, int key){

    int s = 0, e = vec.size()-1;
    int mid = ( s + (e-s)/2);
    int ans1, ans2;
    //first occurence
    while( s <= e){
        if(vec[mid] == key) {
         ans1 = mid;
         e=mid-1;
        } 
        else if(vec[mid] < key) s = mid + 1;
        else e = mid-1;
        
        
        mid = ( s + (e-s)/2);
    }
    s = 0; e = vec.size() - 1;
    //last occurence
    while( s<=e){
        if(vec[mid] == key){
            ans2 = mid;
            s = mid + 1;
        }
        else if(vec[mid] < key) s = mid + 1;
        else e = mid - 1;

        mid = ( s + (e-s)/2);
    }
    return make_pair(ans1, ans2);

}

int main(){
//file_i_o();
vector<int> vec = {0, 1, 1, 1, 1, 2, 2, 2, 3, 4, 4, 5, 10};
int ele = 1;
auto res = first_and_last_occ(vec, ele);

cout<<"first occ : "<<res.first<<"  : last occ : "<<res.second<<endl;

return 0; 
}
*/
int main(){
	file_i_o();
	vector<int> arr {1, 2, 2, 2, 3, 3, 3, 3, 3, 4, 4, 6};
	cout<<frequencyCount(arr, 3);
	return 0;
}
