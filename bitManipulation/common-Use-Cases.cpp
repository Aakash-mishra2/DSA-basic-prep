#include<bits/stdc++.h>
#include<vector>

using namespace std;

//swap two numbers without temp variables
// a = a ^ b;
// b = a ^ b;
// a = a ^ b;

//find missing number in an array
//XOR all array elements and the numbers from 1 to n. The result will be the missing number.

//XOR (a, b) < 0 if they have opposite signs

// any number is power of two
  //  num > 0 and (num & (num -1 )) === 0



//generate all subsets of an array
vector<vector<int>> generateSubsets(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> subsets;

    for (int mask = 0; mask < (1 << n); ++mask) { // Iterate through 2^n masks
        vector<int> subset;
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) { // Check if the i-th bit is set in mask
                subset.push_back(nums[i]);
            }
        }
        subsets.push_back(subset);
    }

    return subsets;
}


//unique numbers
//unique number in 2n+1, 2n+2 an array: xor all numbers one by one
//XOR operation cancel outs duplicate numbers or bits

//unique 3N+1 nubers
// Given 3n+1 numbers where every number is coming thrice except one number find that one unique nubmer

//BitMasking
    // 1. XOR of two unique > 0 (Atleast one set bit)
    // 2. A bit is set when it is present in exactly one of the two numbers
    // 3. take set of numbers with set bit in pos=1 and XOR them for first digit, then XOR rest of numbers for second digit


void uniqueNo2(vector<int> arr){
    int n = arr.size();

    //XOR
    int result = 0;
    for(int i = 0; i<n; i++){
        result = result ^ arr[i];
    }

    // Pos  this result will be xor of the two unique numbers , now pos of set bit         
    int pos = 0;
    int temp = result;
    while((temp&1) == 0) {
        pos++; temp = temp >> 1;
    }

    //Filter out the numbers from the array which have set bit at 'pos'

    int setA = 0;
    int setB = 0;
    int mask = (1<<pos);

    for(int i = 0; i<arr.size(); i++){
        if((arr[i] & mask) > 0) setA = setA ^ arr[i]; 
        else setB = setB ^ arr[i]; 
    }

    cout<< setA <<endl;
    cout<< setB <<endl;
}

// int updateSum(vector<int> &sumArr, int x){
//     //Extract all bits of X
//     for(int i=0; i<32; i++){
//         int ith_bit = x & (1<<i);
//         if( ith_bit ){
//             sumArr[i]++;
//         } 
//     }
// }

void updateSum(vector<int> &sumArr, int x){
    //Extract all bits of X
    for(int i=0; i<32; i++){
        int ith_bit = x & (1<<i);
        if(ith_bit){
            sumArr[i]++;
        }
    }
}
int numFromBits (vector<int> sumArr){
    int num = 0;
    for(int i=0; i<32; i++){
        num += (sumArr[i] * (1<<i));
    }
    return num;
}

int uniqueNo3(vector<int> arr){
    vector<int> sumArr(32, 0);
    for(int x: arr){
        updateSum(sumArr, x);
    }
    for(int i=0; i<32; i++){
        sumArr[i] = sumArr[i]%3;
    }
    //final sum array will be 3*(sum of no. repeating thrice) + 1 times unique number;
    //An Array of Bits ( 0 or 1 )
    return numFromBits(sumArr);
}

int main () {
    vector<int> arr = {1, 3, 5, 4, 3, 1, 5, 5, 1, 3, 7, 7, 7};
    //uniqueNo2(arr); cout<<endl;
    cout<<uniqueNo3(arr); cout<<endl;
}
