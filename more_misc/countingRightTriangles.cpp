#include<bits/stdc++.h>
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
/*
Input:
5
1 2
2 0
2 2
2 3
4 2
Output:
4

Input:
3
0 0
2 0
0 1
Output:
1
*/

class Point
{
public:
    int x, y;

    Point(int x, int y) : x(x), y(y) {}
};
int countTriangles(vector<Point> points, int n){
    unordered_map<int, int> mx;
    unordered_map<int, int> my;
    //load all (x, cntX) pairs in #maps.
    for( int i = 0; i<n; i++){
        Point p = points[i];
        mx[p.x]++; my[p.y]++;
    }
    int ans= 0;
    for( int i = 0; i<n; i++){
        Point p = points[i];
      // avoid counting current point coordinates it's included
        ans += (mx[p.x] - 1)*(my[p.y] - 1);
    }
    return ans;
}
int main(){
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

    cout<<countTriangles(points, N);

    return 0;
}
