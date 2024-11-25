#include<bits/stdc++.h>
using namespace std;

// class Graph{
//     int V;
//     list<int> *l;
//     vector<int> parent;
//     vector<int> distance;

//     public: 
//         // Graph(int v){
//         //     V = v;
//         //     l = new list<int> [V];

//         // }
// }

class Solution {
    private: 
        bool detect(int src, vector<int> adj[], int vis[]){
            vis[src] = 1;
            //store <source node, parent node>
            queue<pair<int, int>> q;
            q.push({src, -1});

            //traverse until queue is not empty
            while(!q.empty()){
                int node = q.front().first;
                int parent = q.front().second;
                q.pop();

                for(auto adjacentNode: adj[node]){
                    // if adjacent node is visited
                    if( !vis[adjacentNode]){
                        vis[adjacentNode] = 1;
                    }
                    else if( parent != adjacentNode) {
                        return true;
                    }
                }
            }
        return false;
        }

        public: 
        void bfs(vector<vector<int>> adj, int source, int V){
            int vis[V] = {0};
            vis[0] = 1;
            queue<int> q;
            //push the initial starting node
 
            bool* visited = new bool[V]{0};
            int *dist = new int [V]{0};
            int *parent = new int[V];

            q.push(source);

            while(!q.empty()){
                //get the topmost element in the queue
                int node = q.front();
                q.pop();
                
                //traverse for all its neighbors
                for( auto it: adj[node] ){
                    if(!vis[it]){
                        vis[it] = 1;
                        q.push(it);
                    }
                }
            }

            //print the shortest distance
            for(int i=0; i<V; i++){
                cout<<"Shortest distance to node"<<i<<" is "<<dist[i]<<endl;
            }

            //print the path from a source to any dest
            // if(dest != -1){
            //     int temp = dest;
            //     while(temp != source ){
            //         cout<<temp<<" -- ";
            //         temp = parent[temp];
            //     }
            //     cout<<source<<endl;
            // }
        }

};

int main() {
    int V;
    vector<int> adj[4] = {{1, 4, 6}, {2}, {1, 3}, {2}};
    vector<vector<int>> adjlist {{}};
    vector<bool> visited(V, 4);

    Solution sol;
    sol.bfs(adjlist, 0, V);
    

    return 0;
}

