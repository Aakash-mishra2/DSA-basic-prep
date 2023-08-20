#include <bits/stdc++.h>
using namespace std;
void file_io()
{
    ios_base::sync_with_stdio;
    cout.tie(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen(" output.txt", "w", stdout);
#endif
}
class Graph
{
    int V;
    list<int> *l;
    vector<int> parent;
    vector<int> distance;
    bool cyclic = false;
    // vector<bool> visited;

public:
    Graph(int v)
    {
        V = v;
        l = new list<int>[V];
        distance.assign(V, 0);
        parent.assign(V, -1);
        // visited.assign(V, false);
    }
    void addEdge(int m, int n, bool undir = true)
    {
        l[m].push_back(n);
        if (undir = true)
            l[n].push_back(m);
    }
    // void dfs(int root)
    // {
    //     cout << root << " ";
    //     for (auto next : l[root])
    //         if (visited[next] == false)
    //         {
    //             visited[next] = true;
    //             if (distance[next] == 0)
    //                 distance[next] = distance[root] + 1;
    //             parent[next] = root;
    //             dfs(next);
    //         }
    //         else
    //             return;
    // }
    void dfsHelper(int node, bool *visited)
    {
        visited[node] = true;
        cout << node << " ";
        for (int nbr : l[node])
        {
            if (!visited[nbr])
            {
                distance[nbr] = distance[node] + 1;
                parent[nbr] = node;
                dfsHelper(nbr, visited);
            }
        }
        return;
    }
    void dfs(int source)
    {
        bool *visited = new bool[V]{0};
        distance[source] = 0;
        parent[source] = 0;
        dfsHelper(source, visited);
    }
    void backtrack(int x)
    {
        cout << "Shortest distance to " << x << " is : " << distance[x] << endl;
        cout << x << " ";
        while (distance[x] != 0)
        {
            cout << " <-- " << parent[x];
            x = parent[x];
        }
        cout << endl;
    }
};

int main()
{
    file_io();
    Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(0, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(3, 4);
    g.addEdge(5, 6);
    return 0;
}