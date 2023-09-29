// set has faster lookup time but no
// direct updation - delete whole entry and
// add new one
#include <bits/stdc++.h>
using namespace std;
void file_io()
{
    ios_base::sync_with_stdio;
    cout.tie();
    cin.tie();
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen(" output.txt", "w", stdout);
#endif
}
class Graph
{
    list<pair<int, int>> *l;
    int V;

public:
    Graph(int v)
    {
        V = v;
        l = new list<pair<int, int>>[V];
    }

    void addEdge(int i, int j, int wt, bool undir = true)
    {
        l[i].push_back({wt, j});
        if (undir)
        {
            l[j].push_back({wt, i});
        }
    }
    void showgraph()
    {
        for (int i = 0; i < V; i++)
        {
            cout << i << "-->";
            for (auto node : l[i])
            {
                cout << "{" << node.first << "," << node.second << "}";
            }
            cout << endl;
        }
    }
/* 29 sept
int sssp(int source, int destination)
    {
        set<pair<int, int>> S;
        vector<int> dist(V, INT_MAX);
        S.insert({0, source}); //distance, node
        while(!S.empty()){
            auto it = S.begin();
            int node = (*it).second;
            int d = (*it).first;
            S.erase(it);
            for(auto nbr : l[node]){
                if( dist[nbr.second] > nbr.first + d ){
                    if(S.find({dist[nbr.second], nbr.second}) != S.end()){
                        S.erase({dist[nbr.second], nbr.second});
                    }
                    dist[nbr.second] = nbr.first + d;
                    S.insert({dist[nbr.second], nbr.second});
                }
            }
        }
        return dist[destination];
    } 
};
*/
    int sssp(int source, int destination)
    {
        set<pair<int, int>> S;
        vector<int> dist(V, INT_MAX);
        dist[source] = 0;
        S.insert({0, source});
        while (!S.empty())
        {
            auto it = S.begin();
            int node = it->second;
            int distTillNow = it->first;
            S.erase(it);

            for (auto nbrPair : l[node])
            {
                int currentEdgWT = nbrPair.first;
                int nbr = nbrPair.second;
                if (distTillNow + currentEdgWT < dist[nbr])
                {
                    // remove old nbr pair
                    auto f = S.find({dist[nbr], nbr});
                    if (f != S.end())
                    {
                        S.erase(f);
                    }

                    dist[nbr] = distTillNow + currentEdgWT;
                    S.insert({dist[nbr], nbr});
                }
            }
        }
        return dist[destination];
    }
};

int main()
{
    file_io();
    Graph g(5);
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 1);
    g.addEdge(0, 2, 4);
    g.addEdge(0, 3, 7);
    g.addEdge(3, 2, 2);
    g.addEdge(3, 4, 3);
    g.showgraph();
    cout << endl;
    cout << g.sssp(0, 4) << endl;
    return 0;
}
