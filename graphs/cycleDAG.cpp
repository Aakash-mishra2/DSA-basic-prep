// will have to maintain nodes present in the current path
//  or call stack. Going to a node in stack and visited means backedge.

#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    list<int> *l;
    vector<bool> visited;
    vector<bool> stack;

public:
    Graph(int v)
    {
        this->V = v;
        l = new list<int>[V];
        visited.assign(V, false);
        stack.assign(V, false);
    }
    void addEdge(int x, int y)
    {
        l[x].push_back(y);
    }
    bool dfs(int source)
    {
        visited[source] = true; // arrive at node
        stack[source] = true;
        for (auto nbr : l[source]) // do some work,
        {
            if (visited[nbr] == false)
            {
                bool nbrfoundCycle = dfs(nbr); // neighbour
                if (nbrfoundCycle)
                { // leads to backedge
                    return true;
                }
            }
            else if (stack[nbr] == true) // if backedge found
                                         // here itself
            {
                return true;
            }
        }
        stack[source] = false; // leave node
        return false;
    }
    bool containsCycle() // helper function
    {
        return dfs(0);
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
