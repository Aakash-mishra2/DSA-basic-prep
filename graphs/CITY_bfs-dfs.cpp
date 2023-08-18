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
class node
{
public:
    string name;
    list<string> nbrs;
    node(string city) : name(city) {}
};

class Graph
{
    unordered_map<string, node *> m;
    unordered_map<string, bool> visited;

public:
    Graph(vector<string> cities)
    {
        for (auto i : cities)
        {
            m[i] = new node(i);
        }
    }
    void addEdge(string x, string y, bool undir = false)
    {
        m[x]->nbrs.push_back(y);
        if (undir == true)
        {
            m[y]->nbrs.push_back(x);
        }
    }
    void printAdjList()
    {
        for (auto cityPair : m)
        {
            auto city = cityPair.first;
            node *cityNode = cityPair.second;
            cout << city << "-->";
            for (auto nbr : cityNode->nbrs)
            {
                cout << nbr << ",";
            }
            cout << endl;
        }
    }
    void unvisitAll()
    {
        for (auto city : m)
        {
            visited[city.first] = false;
        }
    }
    friend void dfs(Graph, string);
    friend void bfs(Graph g);
    void DFS()
    {
        for (auto city : m)
        {
            dfs(*this, city.first);
        }
    }
};
void bfs(Graph g)
{
    queue<string> q;
    for (auto cityPair : g.m)
    {
        q.push(cityPair.first);
        while (!q.empty())
        {
            string current_node = q.front();
            cout << current_node << " ";
            for (auto next_nodes : g.m[current_node]->nbrs)
            {
                q.push(next_nodes);
            }
            q.pop();
        }
        cout << endl;
    }
}
void dfs(Graph g, string current)
{
    if (g.visited[current] == false)
    {
        cout << current << " ";
        for (auto next : g.m[current]->nbrs)
        {
            if (!g.visited[next])
                g.visited[next] = true;
            dfs(g, next);
        }
    }
    else
        return;
}
int main()
{
    file_io();
    vector<string> cities = {"Delhi",
                             "London",
                             "Paris",
                             "New York"};
    Graph g(cities);
    g.addEdge("Paris", "New York");
    g.addEdge("Delhi", "Paris");
    g.addEdge("New York", "London");
    g.addEdge("Delhi", "London");
    cout << "PRINT GRAPH" << endl;
    g.printAdjList();
    cout << "BREADTH-FIRST-SEARCH" << endl;
    bfs(g);
    g.unvisitAll();
    cout << " DEPTH-FIRST-SEARCH" << endl;
    g.DFS();
    return 0;
}