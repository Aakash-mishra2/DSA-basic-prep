#include <bits/stdc++.h>
using namespace std;
// bfs smallest path very first time node is updated
// its via shortest path from source and larger paths rest of time.
// levels of nodes are shortest distance;
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

public:
    Graph(int v)
    {
        V = v;
        l = new list<int>[V];
        distance.assign(V, 0);
        parent.assign(V, -1);
    }
    void addEdge(int m, int n, bool undir = true)
    {
        l[m].push_back(n);
        if (undir = true)
            l[n].push_back(m);
    }
    void bfs(int root)
    {
        vector<bool> visited(V, false);
        queue<int> q;
        q.push(root);
        distance[root] = 0;
        parent[root] = root;
        visited[root] = true;
        while (!q.empty())
        {
            cout << q.front() << " ";
            for (auto next : l[q.front()])
            {
                if (visited[next] == false)
                {
                    q.push(next);
                    parent[next] = q.front();
                    distance[next] = distance[q.front()] + 1;
                    visited[next] = true;
                }
            }
            q.pop();
        }
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
    g.bfs(1);
    cout << endl;
    g.backtrack(5);
    return 0;
}