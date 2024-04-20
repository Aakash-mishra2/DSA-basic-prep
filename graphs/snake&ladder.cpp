#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <string>
#include <queue>
using namespace std;

class Graph {
    
    public:
    int V;
    list<int> *l;
    vector<int> parent ( V, -1)
    Graph(int v){
        this->V = v;
        l = new list<int>[V + 1];
    }
    
    void addEdge (int i, int j, bool undir=true){
        l[i].push_back(j);
        if( undir ){
            l[j].push_back(i);
        }
    }
    
    int minCostBfs(int source){
        queue<int> q;
        bool *visited = new bool[V]{0};
        vector<int> distance (V, 0);
        
        q.push(source);
        visited[source] = true;
        while( !q.empty()){
            int f = q.front();
            cout<<q.front()<<endl;
            q.pop();
            
        for( auto nbr: l[f]){
            if( visited[nbr] == false ){
                q.push(nbr);
                visited[nbr] = true;
                distance[nbr] = distance[node] + 1;
                }
            }
        }
        return source;
    }
    
    // void printList () {
    //     for( auto city: L) {
    //         cout<<" "<<city->first<<" "<<city->second<<" "<<endl;
    //     }
    //     cout<<endl;
    // }
    
};

int min_dice_throws ( int n, vector<pair<int, int>> snakes, vector<pair<int, int>> ladders){
    vector<int> board ( n+1, 0);
    for( auto sp: snakes ){
        int s = sp.first;
        int e = sp.second;
        board[s] = e - s;
    }
    for( auto lp: ladders){
        int s = lp.first;
        int e = lp.second;
        board[s] = e - s;
    }
    Graph g(n+1);
    for(int u=1; u<n; u++){
        for(int dice = 1; dice <=6; dice++){
            
            int v = u + dice;
            v += board[v];
            if( v <= n){
                g.addEdge(u, v);
            }
        }
    }
    return g.minCostBfs(1, n);
    
}
