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
    
