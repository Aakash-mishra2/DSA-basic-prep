  #include<iostream>
using namespace std;

int uniquePaths1(int r, int c){
    vector<int> prev(c, 0), curr(c, 0);
    for(int i = 0; i<r; i++){
        for(int j = 0; j<c; j++){
            if( i == 0 || j == 0) curr[j] = 1;
            else {
                int up = 0, left = 0;
                if( i > 0) up = prev[j];
                if( j > 0) left = curr[j-1];
                curr[j] = up + left;
            }
            prev = curr;
        }
    }
    return prev[c-1];
}

int uniquePaths2(vector<vector<int>> obstacleGrid, int r, int c){
    int rows = obstacleGrid.size();
    int colm = obstacleGrid[0].size();
    vector<int> prev (colm, 0), curr( colm, 0);
    for( int i = 0; i<rows; i++){
        for(int j = 0; j<colm; j++){
            if(ostacleGrid[i][j] == 1)curr[j] = 0;
            else if( i == 0 and j == 0) curr[j] = 1;
            else{
                int up = 0, left = 0;
                if(i>0) up = prev[j];
                if(j>0) left = curr[j-1];
                curr[j] = up + left; 
            }
        }
        prev = curr;
    }
    return prev[j-1];
}
