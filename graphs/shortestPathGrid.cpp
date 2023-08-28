#include <iostream>
#include <vector>
#include <set>
#include <climits>
using namespace std;
class Node
{
public:
    int x;
    int y;
    int dist;
    Node(int x, int y, int dist) : x(x), y(y), dist(dist) {}
};
class Compare
{
public:
    bool operator()(const Node &a, const Node &b)
    {
        return a.dist <= b.dist;
    }
};

int shortest_path(vector<vector<int>> grid)
{
    int r = grid.size();
    int c = grid[0].size();
    int i = 0;
    int j = 0;

    vector<vector<int>> dist(r + 1, vector<int>(c + 1, INT_MAX));
    dist[i][j] = grid[0][0];
    // set three things i, j, dist sorted based on distance
    set<Node, Compare> s;
    s.insert(Node(0, 0, dist[0][0]));
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};
    while (!s.empty())
    {
        auto it = s.begin();
        int cx = it->x;
        int cy = it->y;
        int cdist = it->dist;
        s.erase(it);
        for (int k = 0; k < 4; k++)
        {
            int nx = cx + dx[k];
            int ny = cy + dy[k];
            if (nx >= 0 and nx < r and ny >= 0 and ny < c and cdist + grid[nx][ny] < dist[nx][ny])
            {

                Node temp(nx, ny, dist[nx][ny]);
                if (s.find(temp) != s.end())
                {
                    s.erase(s.find(temp));
                }

                dist[nx][ny] = grid[nx][ny] + cdist;
                s.insert(Node(nx, ny, dist[nx][ny]));
            }
        }
    }
    return dist[r - 1][c - 1];
}