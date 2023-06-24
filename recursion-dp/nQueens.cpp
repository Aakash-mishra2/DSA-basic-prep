#include <bits/stdc++.h>
using namespace std;
void printBoard(int board[][20])
{
}
bool canPlace(int board[][20], int n, int x, int y)
{
    // column
    // left daigonal
    // right daigonal
}

bool solvedQueen(int n, int board[][20], int i)
{
    if (i == n)
    {
        printBoard(n, board);
        return true;
    }

    for (int j = 0; j < n; j++)
    {
        if (canPlace(board, n, i, j))
        {
            board[i][j] = 1;
            bool success = solvedQueen(n, board, i + 1);
            if (success)
            {
                return true;
            }
            // backtrack
            board[i][j] = 0;
        }
    }
    return false;
}

int main()
{

    return 0;
}