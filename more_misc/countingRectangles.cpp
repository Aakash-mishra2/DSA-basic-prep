#include <bits/stdc++.h>
using namespace std;
/*
8
0 0
0 1
1 1
1 0
2 1
2 0
3 1
3 0
*/
void file_io()
{
    ios_base::sync_with_stdio;
    cout.tie(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
class Point
{
public:
    int x, y;

    Point(int x, int y) : x(x), y(y) {}
};
class Compare
{
public:
    bool operator()(const Point p1, const Point p2)
    {
        if (p1.x == p2.x)
        {
            return p1.y < p2.y;
        }
        return p1.x < p2.x;
    }
};

int countingRectangles(vector<Point> points)
{
    int ans = 0;
    set<Point, Compare> set;
    for (int i = 0; i < points.size(); i++)
    {
        set.insert(points[i]);
    }

    // 2. brute force logic for two points
    for (auto it = set.begin(); it != prev(set.end()); it++){
        for( auto jt = next(it); jt != set.end(); jt++){
            Point p1 = *it;
            Point p2 = *jt;
            //small check to make sure p1 and p2 are diagonally opposite
            if( p1.x == p2.x or p1.y == p2.y) continue;

            Point p3(p1.x, p2.y);
            Point p4(p2.x, p1.y);

            //look up
            if(set.find(p3)!=set.end() and set.find(p4)!=set.end()){ 
                ans += 1;
            }
        }
    }
    // why? lec176
    return ans/2;
}

int main()
{
    file_io();
    int N;
    cin >> N;
    int x, y;

    vector<Point> points;
    for (int i = 0; i < N; i++)
    {
        cin >> x >> y;
        Point p(x, y);
        points.push_back(p);
    }

    cout << countingRectangles(points);

    return 0;
}
