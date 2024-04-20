/*
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
                distance[nbr] = distance[f] + 1;
                }
            }
        }
        return source;
    }
    void dfs(int source){
        bool *visited = new bool[V]{0};
        int *parent = new int[V]{-1};
        dfsHelper(source, visited, -1);
    }
    
    bool dfsHelper(int node, bool* visited, int parent){
        visited[node] = true;
        cout<<node<<endl;
        // make a dfs call on all its unvisited neighbours
        for(int nbr: l[node]){
            if( !visited[nbr] ){
                bool nbrFoundACycle = dfsHelper(nbr, visited, node);
                if( nbrFoundACycle ){
                    return true;
                }
            }
            else if( nbr != parent ){
                return true;
            }
        }
        return false;
    }
    
    bool contains_cycle(){
        vector<bool> visited(V, false);
        dfs(0);
    }
};


int main()
{
    Graph g(3);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
 //   g.minCostBfs(1);
 if(g.contains_cycle()) cout<<"true";
 else cout<<"false";
    return 0;
}
    */

#include<bits/stdc++.h>
using namespace std;
class Graph{
    list<int>* l;
    int V;
    
    public:
    vector<bool> visited;
        Graph(int v){
            V = v;
            l = new list<int>[V];
            visited.assign(V, false);
        }
        void addEdge(int x, int y, bool undir = true){
            l[x].push_back(y);
            if(undir){
                l[y].push_back(x);
            }
        }
        bool dfs(int node, int parent){
            visited[node]=true;
            cout<<node<<endl;
            for( int nbrs : l[node]){
                if(!visited[nbrs]){
                    bool nbrs_cycle = dfs(nbrs, node);
                    if(nbrs_cycle == true) {
                        return true;
                    }
                }
                else if(nbrs != parent){
                    return true;
                }
            }
            return false;
        }
};
bool contains_cycle(int B,vector<pair<int,int> > edges){
    Graph g(B);
    for(auto i: edges){
        g.addEdge(i.first, i.second);
    }
        for(int i = 0; i<B; i++){
            if(!g.visited[i]){
                if(g.dfs(i, -1) == true){
                    return true;
                }
            }
        }
    return false;
}    
    
