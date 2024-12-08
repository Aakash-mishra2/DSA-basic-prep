#include<bits/stdc++.h>
using namespace std;
void fileIo(){
    ios_base::sync_with_stdio(false);
    cout.tie(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("./input.txt","r",stdin);
    freopen("./output.txt","w",stdout);
    #endif
}

//pascal triangle
vector<vector<int>> binomialCoefficients (int n, int k){
    vector<vector<int>> table(n+1, vector<int>(k+1, 0));
    for(int i = 0; i<=n; i++){
        for(int j = 0; j<= min(i, k); j++){

            //base case
            if(j==0 || j==i){
                table[i][j] = 1;
            }
            else {
                table[i][j] = table[i-1][j-1] + table[i-1][j];
            }
        }
    }
    return table;
}

//what should be min no of people that should be present in a hall so that there's atleast 
//50% chance of two people having same birthday.
int birthDayParadox () {
    int people = 0; float num = 365, denom = 365;

    float prob_diff_bday = 1;
    while(1){
        prob_diff_bday = prob_diff_bday * (num/denom);
        cout<<"People "<<people <<" Prob: "<<prob_diff_bday <<endl;
        num = num - 1;
        people = people + 1;
    }

    cout<<"Final Ans " <<people<<endl;
    return 0;
}

//how many BST are possible from given n number of nodes
int countBST(int n){
    // given n nodes, catalan no = how many bst possible
    if( n == 0 or n==1){
        return 1;
    }
    int ans = 0;
    for(int i = 1; i<=n; i++){
        int x = countBST(i-1);
        int y = countBST(n-i);

        ans += x*y;
    }

    return ans;
}

int countBSTdp(int n, int dp[]){
    if( n==0 or n == 1){
        return 1;
    }
    if(dp[n] != 0){
        return dp[n];
    }

    int ans = 0;
    for(int i = 1; i<=n; i++){
        int x = countBSTdp(i-1, dp);
        int y = countBSTdp(n-i, dp);
        ans += x*y;
    }

    return dp[n] = ans;

}

int main () {
    fileIo();

    // int n; cin>>n;
    // int queries = 2;
    //vector<vector<int>> table = binomialCoefficients(n, n);
    // while(queries--){
    //     int k; cin>>k;
    //     if(k<=n){
    //         cout << table[n][k] <<endl;
    //     }
    // }

    //birthDayParadox();
    int t = 2;
    while(t--){

    int n; cin>>n;
    int dp[n+1] = {0};
    //cout<<countBST(n) <<endl;
    cout<<countBSTdp(n, dp);
    cout<<endl;
    }
    return 0;
}
