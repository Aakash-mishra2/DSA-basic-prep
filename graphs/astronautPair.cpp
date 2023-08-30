#include <bits/stdc++.h>
using namespace std;
class Graph
{
    int V;
    list<int> *l;

public:
    vector<bool> visited;

public:
    Graph(int v) : V(v)
    {
        l = new list<int>[V];
        visited.assign(V, false);
    }
    void addEdge(int x, int y, bool undir = true)
    {
        l[x].push_back(y);
        if (undir)
        {
            l[y].push_back(x);
        }
    }
    int dfs(int source)
    {
        int count = 1;
        for (auto nbr : l[source])
        {
            if (!visited[nbr])
            {
                visited[nbr] = true;
                count += dfs(nbr);
            }
        }
        return count;
    }
};
int count_pairs(int N, vector<pair<int, int>> astronauts)
{
    // complete this method
    vector<int> scc;
    Graph g(N);
    for (auto p : astronauts)
    {
        g.addEdge(p.first, p.second);
    }
    for (int i = 0; i < N; i++)
    {
        if (!g.visited[i])
        {
            g.visited[i] = true;
            scc.push_back(g.dfs(i));
        }
    }
    int answer = 0;
    int comp = scc.size();
    for (int i = 0; i < comp; i++)
    {
        for (int j = i + 1; j < comp; j++)
        {
            answer += scc[i] * scc[j];
        }
    }
    return answer;
}