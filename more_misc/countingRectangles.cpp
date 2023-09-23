#include <bits/stdc++.h>
using namespace std;
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
//custom comparator for Points set
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
class Compare
{
public:
    bool operator()(const Point p1, const Point p2){
            if(p1.x == p2.x){
                return p1.y < p2.y;
            }
            else return p1.x < p2.x;
    }
};

int countingRectangles(vector<Point> points)
{
    set<Point, Compare> s;
    int ans = 0;
    for(int i=0; i<points.size(); i++){
        s.insert(points[i]);
    }
    //brute force p2, p1;
    for( auto it = s.begin(); it != prev(s.end()); it++){
        for( auto jt = next(it); jt != s.end(); jt++){
            Point p1 = *it;
            Point p2 = *jt;
            // make sure diagonally opp
            if( p1.x == p2.x or p1.y == p2.y) continue;
            Point p3(p1.x, p2.y);
            Point p4(p2.x, p1.y);
            // lookup p3, p4
            if((s.find(p3) != s.end())  and (s.find(p4)!=s.end()))
                ans++;

        }
    }
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
