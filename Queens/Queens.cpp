#include <iostream>
#include <cmath>
using namespace std;

const int n = 8;

bool check(int board[], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        if (board[i] == col || abs(board[i] - col) == abs(i - row))
        {
            return false;
        }
    }
    return true;
}

void printBoard(int board[])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i] == j)
            {
                cout << "🜲 ";
            }
            else
            {
                cout << ". ";
            }
        }
        cout << endl;
    }
    cout << endl;
    return;
}

void solveQueens(int board[], int row, int& solutions)
{
    if (row == n)
    {
        solutions++;
        printBoard(board);
        return;
    }
    for (int col = 0; col < n; col++)
    {
        if (check(board, row, col))
        {
            board[row] = col;
            solveQueens(board, row + 1, solutions);
        }
    }
    return;
}

int main()
{
    int board[n];
    int solutions = 0;
    solveQueens(board, 0, solutions);
    cout << "Всего решений: " << solutions << endl;
    return 0;
}
