#include <bits/stdc++.h>
using namespace std;

int dfs(vector<vector<int>> grid, int x, int y, int r, int c, vector<vector<bool>>& visited ){

    visited[x][y] = true;
    int dx[] = {-1 , 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    int lengthSoFar = 1;
    for( int i = 0; i<4; i++){
        int  nx = x + dx[i], ny = y + dy[i];

        if(grid[nx][ny] == 1 and !visited[nx][ny] and nx<r and ny<c and nx>=0 and ny>= 0)
            lengthSoFar += dfs(grid, nx, ny,r, c, visited);
    }
    return lengthSoFar;
}

int largestIsland(vector<vector<int>> grid){


    int answer = -1;
    int rows = grid.size();
    int columns = grid[0].size();
    vector<vector<bool>> visited (rows, vector<bool>(columns, false));
    for(int i = 0; i<rows; i++){
        for(int j = 0; j<columns; j++){
            if(!visited[i][j] and grid[i][j] == 1){
                answer = max(answer, dfs(grid, i, j, rows, columns, visited));
            }
        }
    }
    return (answer == -1)? 0 : answer;
}
