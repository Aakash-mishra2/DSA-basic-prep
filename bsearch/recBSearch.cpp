#include<bits/stdc++.h>
using namespace std;
inline namespace array_nature{
	bool asc = true;
	bool dsc = true;
}
template<typename T>
ostream& operator<<(ostream& os, vector<T>& star){                 //print Array overload 
	for(T i : star){ os<<i<<" "; } return os; }

int Bsearch(vector<int>& vec, int& key, int start, int end){    //recursive Binary Search
	int ans, mid = start + (end - start)/2;
	if(start > end) return -1;
	if(vec[mid] == key){ ans = mid; } 
	else if(asc == true){ 									//if sorted in ascending order
		if (key > vec[mid]) ans = Bsearch(vec, key, mid+1, end);       //search right half
		else ans = Bsearch(vec, key, start, mid -1);                    //search left half
	}
	else if(dsc == true){								  //if sorted in descending order
		if (key > vec[mid]) ans = Bsearch(vec, key, start, mid - 1);   //search left half
		else ans = Bsearch(vec, key, mid + 1, end);                    //search left half
	}
	return ans;
}
bool isSorted_bothWays(vector<int>& arr,int ind){
	if(ind == 0 ) return asc||dsc ;

	if(asc) asc = asc && (arr[ind] >= arr[ind - 1]);
	if(dsc) dsc = dsc && (arr[ind] <= arr[ind - 1]);

	return isSorted_bothWays(arr, ind- 1);
}
void linear_reverse_array(vector<int>& arr){ 		//two pointer linear reverse of array
	int i = 0, j = arr.size() - 1;
	while(i<j)	{
		int temp = arr[i]; arr[i] = arr[j]; arr[j] = temp;
		i++; j--; }
}
int main(){
	vector<int> arr { -17, 4, 5, 10, 12, 14, 19};						//ascending sorted

	linear_reverse_array(arr);											//to reverse sorted

	// cout<<" Enter key value to search from { "<<arr<<" } : "<<endl;
	// int key; cin>>key;
	int key = -17;
	for(auto i: arr) cout<<i<<" ";
	if(isSorted_bothWays(arr, arr.size() - 1)){
		int pos = Bsearch(arr, key, 0, arr.size() - 1);
		if( pos != -1) cout<<" Key "<<key<<" found at : "<<pos + 1<<" Position."<<endl;
		else cout<< " key not found . "<<endl;
	}
	else { cout<<" Array not sorted. "<<endl; } 
	return 0;
}
