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
class Node
{
public:
    string name;
    list<string> nbrs;
    Node(string city) : name(city) {}
};

class Graph
{
public:
    // all nodes //hashmap of cities and pointer node
    int V;
    unordered_map<string, Node *> m;

public:
    Graph(vector<string> cities)
    {
        for (auto city : cities)
        {
            m[city] = new Node(city);
        }
    }
    void addEdge(string x, string y, bool undir = false)
    {
        m[x]->nbrs.push_back(y);
        if (undir)
            m[y]->nbrs.push_back(x);
    }
    void printAdjList()
    {
        for (auto cityPair : m)
        {
            auto city = cityPair.first;
            Node *cityNode = cityPair.second;
            cout << city << "-->";
            for (auto nbr : cityNode->nbrs)
            {
                cout << nbr << ",";
            }
            cout << endl;
        }
    }
};

int main()
{
    file_io();
    vector<string> cities = {"Delhi",
                             "London",
                             "Paris",
                             "New York"};
    Graph g(cities);
    g.addEdge("Delhi", "London");
    g.addEdge("New York", "London");
    g.addEdge("Delhi", "Paris");
    g.addEdge("Paris", "New York");
    g.printAdjList();
}