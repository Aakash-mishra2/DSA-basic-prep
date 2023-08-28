#include <bits/stdc++.h>
using namespace std;
int dfs(vector<vector<int>> grid, int i, int j, vector<vector<bool>> &visited, int r, int c)
{
    int length = 0;
    if (grid[i][j] == 1)
        length = 1;

    int dx[] = {+1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};
    for (int k = 0; k < 4; k++)
    {
        int nx = i + dx[k];
        int ny = j + dy[k];
        if (nx >= 0 and ny >= 0 and nx < r and ny < c and grid[nx][ny] == 1 and !visited[nx][ny])
        {
            visited[nx][ny] = true;
            length += dfs(grid, nx, ny, visited, r, c);
        }
    }
    return length;
}
int largest_island(vector<vector<int>> grid)
{
    int answer = -1, r = grid.size(), c = grid[0].size();
    vector<vector<bool>> visited(r, vector<bool>(c, false));
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (!visited[i][j] and grid[i][j] == 1)
            {
                visited[i][j] = true;
                answer = max(answer, dfs(grid, i, j, visited, r, c));
            }
        }
    }
    return ((answer == -1) ? 0 : answer);
}