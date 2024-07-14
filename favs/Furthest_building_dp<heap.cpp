https://leetcode.com/problems/furthest-building-you-can-reach/description/?envType=daily-question&envId=2024-07-14

class Solution {
public:
    int f(int node, int x, int y, int ladder, int bricks, vector<vector<int>> &dp,vector<int> heights)
{
    int temp = 0, left = 0, right = 0;
    if (node == heights.size())
        return node;
    if (x > ladder || y > bricks)
        return node;
    if (dp[x][y] != -1)
        return dp[x][y];

    if ((node < heights.size()-1) && (heights[node] >= heights[node + 1]))
    {
        temp = f(node + 1, x, y, ladder, bricks, dp, heights);
    }
    else
    {
        left = f(node + 1, x + 1, y, ladder, bricks, dp, heights);

        int diff = (node < heights.size() - 1) ? abs(heights[node] - heights[node + 1]) : 0;
        right = f(node + 1, x, y + diff, ladder, bricks, dp, heights);
    }
    return dp[x][y] = max(left, max(temp, right));
}
// using recn-tle, dp-top/down-MLE... minHeap and counting
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(int i = 1; i<heights.size(); i++){
            int diff = heights[i] - heights[i-1];
            if( diff > 0) pq.push(diff);
            if( pq.size() > ladders){
                if( pq.top() <= bricks ) bricks -= pq.top(), pq.pop();
                else return i - 1;
            }
        }
        return heights.size() - 1;
    }
};
