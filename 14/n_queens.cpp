#include <bits/stdc++.h>

using namespace std;

int boardSize = 4;

bool isSafe(bool board[4][4], int row, int col)
{
    for (int i = 0; i < col; ++i)
    {
        if (board[row][i])
            return false;
    }

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j])
            return false;
    }

    for (int i = row, j = col; j >= 0 && i < boardSize; ++i, --j)
    {
        if (board[i][j])
        {
            return false;
        }
    }

    return true;
}

void printSolution(bool board[4][4])
{
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; i < 4; ++j)
        {
            if (board[i][j])
                cout << "*\t";
            else
                cout << "-\t";
        }
        cout << endl;
    }
}

bool solveNQ(bool board[4][4], int n, int col)
{
    //If all queens are placed
    if (col >= n)
        return true;

    //Consider this column and try placing it
    for (int i = 0; i < boardSize; ++i)
    {
        if (isSafe(board, i, col))
        {
            board[i][col] = true;

            if (solveNQ(board, i, col + 1))
                return true;

            board[i][col] = false;
        }
    }

    return false;
}

int main()
{
    int n;
    cout << "Enter the number of queens : ";
    cin >> n;

    bool board[4][4];

    if (solveNQ(board, n, 0))
        printSolution(board);

    getchar();
    getchar();

    return true;
}