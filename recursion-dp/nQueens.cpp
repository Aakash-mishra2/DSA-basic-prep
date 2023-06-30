#include <bits/stdc++.h>
using namespace std;
void printBoard(int n, int board[][20])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}
bool canPlace(int board[][20], int n, int x, int y)
{
    for (int i = 0; i < x; i++)
    {
        if (board[i][y] == 1)
            return false;
    }
    for (int i = 0; i < x; i++)
    {
        if (board[i][i] == 1)
            return false;
    }
    int i = x, j = y;
    while (i >= 0 and j >= 0)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
        i--;
        j--;
    }
    i = x, j = y;
    while (i >= 0 and j < n)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
        i--;
        j++;
    }
    return true;
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
            board[i][j] = 0;
        }
    }
    return false;
}

int main()
{
    int n;
    cin >> n;
    int board[20][20] = {0};
    solvedQueen(n, board, 0);

    return 0;
}