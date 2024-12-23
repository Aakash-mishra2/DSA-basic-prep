int findPivotElement(vector<int>& nums){
    int n = nums.size(), s = 0, e = n-1, mid =s + (e-s)/2;
    while( s < e){
        if(nums[mid] >= nums[0]) s = mid+1;
        else e = mid;

        mid = s + (e-s)/2;
    }
    return s;
}
int binarySearch(vector<int>& nums, int s, int e, int key){
    int mid = s + (e-s)/2;
    while( s <= e){
    cout<<"start: "<<s<<" "<<"end: "<<e<<endl;
        if(key == nums[mid]) return mid;
        else if ( key > nums[mid]) s = mid + 1;
        else e = mid - 1;

        mid = s + (e-s)/2;
    }
    return -1;
}

int rotatedSearch(vector<int>& arr, int ele){
    int s = 0, e = arr.size() - 1;
    int n = arr.size();
    int pivot = findPivotElement(arr);
    //cout<<"pivot"<<pivot;
    if (ele >= arr[pivot] && ele <= arr[n-1]) return binarySearch(arr, pivot, n-1, ele );
    else return binarySearch(arr, 0, pivot-1, ele); 

}
int main(){
    fileIo();
    vector<int> arr = {7, 8, 9, 0, 1, 2, 4, 5, 6};
    int ele = 4;
  
    cout<<" Ele" <<ele << " at index" << minSwaps(arr)<<endl;
    return 0;
}
