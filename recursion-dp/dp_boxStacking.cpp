#include<bits/stdc++.h>
using namespace std;

class Graph {

    list<pair<int, int>>* l;
    int V;
    
    public:
    Graph(int v)
    {
        V = v;
        l = new list<pair<int, int>>[V];
    }

    void addEdge(int u, int v, int wt, bool undir = true){
        l[u].push_back({wt, v});
        if(undir){
            l[v].push_back({wt, u});
        }
    }

    int dijkstra(int source, int destination){
        //Data structure
        vector<int> dist(V, INT_MAX);
        set<pair<int, int>> s;

        //1. Init
        dist[source] = 0;
        s.insert({0, source});

        while(!s.empty()){
            auto it = s.begin();
            int node = it->second;
             int nodeDist = it->first;
             s.erase(it); //Pop

             //Iterate over the nbrs of node
             for(auto nbrPair: l[node]){

                //.... 
                int nbr = nbrPair.second;
                int currentEdge = nbrPair.first;

                if(nodeDist + currentEdge < dist[nbr]){
                    
                    //remove if nbr already exists in the set
                    
                    auto f = s.find({ dist[nbr], nbr});
                    if( f!=s.end()){
                        s.erase(f);
                    }              

                    //insert the updated value with the new dist     
                    dist[nbr] = nodeDist + currentEdge;
                    s.insert({ dist[nbr], nbr});

                }
             }
        }
        //single source shortest dist to all nodes
         for(int i = 0; i< V; i++){
            cout<<"Node "<< i <<": Dist "<<dist[i] <<endl;
        }

        return dist[destination];
    }
};


int coinsChange (vector<int> coins, int M, int ans) {
    int soln =  INT_MAX;
    
    if( M <= 0 ){
        return ans;
    }

    for(int i = 0; i<coins.size(); i++){
        soln = min(soln, coinsChange(coins, M - coins[i], ans + 1));
    }
    return soln;
}

//Bottom up approach
int minNumberOfCoinsForChange(int m, vector<int> denoms){
    vector<int> dp(m+1, 0);
    dp[0] = 0;
    for(int i = 1; i<=m; i++){
        dp[i] = INT_MAX;
        for(int c : denoms ){
            if(i - c >= 0 and dp[i-c] != INT_MAX){
                dp[i] = min(dp[i], dp[i-c] + 1);
            }
        }
    }
    return dp[m] == INT_MAX ? -1 : dp[m];
}

int min_jumps (vector<int> arr, int n, vector<int> dp, int i=0){

    //base case
    if( i== n-1 ){
        return 0;
    }
    if ( i>= n){
        return INT_MAX;
    }

    // rec case
    if( dp[i] != 0){
        return dp[i];
    }

    //assume 
    int steps = INT_MAX;
    int max_jump = arr[i];

    for( int jump=1; jump <= max_jump; jump++){
        int next_cell = i + jump;
        int subprob = min_jumps(arr, n, dp, next_cell);
        if(subprob != INT_MAX){
            steps = min(steps, subprob + 1);
        }
    }
    return dp[i] = steps;
}

//bottom up approach
int getMinCost(vector<int> stones, vector<int> dp){
    int n = stones.size();
    dp[1] = abs(stones[1] - stones[0]);

    for(int i=2; i<n; i++){
        // int op1 = abs(stones[i] - stones[i-1]) + dp[i-1];
        // int op2 = abs(stones[i] - stones[i-2]) + dp[i-2];
        dp[i] = min(abs(stones[i] - stones[i-1]) + dp[i-1], abs(stones[i] - stones[i-2]) + dp[i-2]);
    }
    return dp[n-1];
}

int maxNonAdjacentSum (vector<int> elements){
    int ans = 0, n = elements.size();

    vector<int> dp(n+1, 0);

    dp[0] = elements[0];
    dp[1] = elements[1];

    for(int i = 2; i<n; i++){

        dp[i] = max(elements[i] + dp[i-2], dp[i-1]);
    }

    return dp[n-1];
}

int longestIncrSubseq (vector<int> elements){

    int n = elements.size();
    vector<int> dp(n, 1);

    int len = 1;
    for(int i = 1; i<n; i++){
        for(int j = 0; j<i; j++){
            if(elements[i] > elements[j]){
                dp[i] = max(dp[i], 1+dp[j]);
                len = max(len, dp[i]);
            }
        }
    }
    return len;
}

bool compareBoxes(vector<int> b1, vector<int> b2){
    return b1[2] < b2[2];
}

bool canPlace(vector<int> b1, vector<int> b2){

    if(b1[0] > b2[0] and b1[1] > b2[1] and b1[2] > b2[2]){
        return true;
    }
    return false;
}

int boxStacking(vector<vector<int>> boxes){

    //1.sorting
    sort(boxes.begin(), boxes.end(), compareBoxes);
    int n = boxes.size();

    //2.DP
    vector<int> dp(n+1, 0);

    for(int i=0; i<n; i++){
        dp[i] = boxes[i][2]; //height of ith box
    }

    //3. check for all boxes whose index is less than i
    for(int i=1; i<n; i++){
        //check for all boxes whose index is less than i
        for(int j=0; j<i; j++){
            if(canPlace(boxes[j], boxes[i])){
                int current_height = boxes[i][2];
                if(dp[j] + current_height > dp[i]){
                    dp[i] = dp[j] + current_height;
                }
            }
        }
    }
    int max_height = 0;
    for(int i=0; i<n; i++){
        max_height = max(max_height, dp[i]);
    }
    return max_height;
}

int main() {
    // vector<int> arr {3, 4, 2, 1, 2, 3, 7, 1, 1, 3};
    // int M = 4;
    // int ans = 0;

    //create an array for dp
    //int n = arr.size();


    // vector<int> stones = {3, 4, 2, 1, 2, 3, 7, 1, 1, 3};
    // int n = stones.size();
    // vector<int> dp(n, 0);

    // dp[1] = abs(stones[1] - stones[0]);


    // vector<int> elements = {50, 4, 10, 8, 30, 100};
    // cout<<longestIncrSubseq(elements)<<endl;

    //cout<<maxNonAdjacentSum(elements)<<endl;


    //cout<<getMinCost(stones, dp);

    //cout<<"Min coins: "<<min_jumps(arr, n, dp, 0)<<endl;
    vector<vector<int>> boxes = {
        {2, 1, 2},
        {2, 2, 1},
        {3, 2, 3},
        {2, 3, 4},
        {2, 3, 4},
        {4, 4, 5},
        {2, 2, 8}
    };

    int height = boxStacking(boxes);

    cout<<"height of largest stack "<<height;

    return 0;
}
