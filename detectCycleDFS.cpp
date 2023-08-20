#include <bits/stdc++.h>
using namespace std;
// cycle detection using bfs code in udemy assignment
class Graph
{
    int V;
    list<int> *l;
    vector<bool> visited;

public:
    Graph(int v)
    {
        this->V = v;
        l = new list<int>[V];
        visited.assign(V, false);
    }
    void addEdge(int x, int y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }
    bool dfs(int node, int parent)
    {
        visited[node] = true;
        for (auto nbr : l[node])
        {
            if (!visited[nbr])
            {
                bool nbrFoundCycle = dfs(nbr, node);
                if (nbrFoundCycle)
                    return true;
            }
            else if (nbr != parent)
                return true;
        }
        return false;
    }
    bool containsCycle()
    {
        return dfs(0, -1);
    }
};

bool contains_cycle(int V, vector<pair<int, int>> edges)
{
    Graph g(V);
    for (auto edge : edges)
    {
        g.addEdge(edge.first, edge.second);
    }
    return g.containsCycle();
}
