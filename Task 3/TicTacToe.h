#pragma once
#include <iostream>
using namespace std;
class TicTacToe
{
private:
    char board[3][3];

public:
    TicTacToe();

    friend ostream &operator<<(ostream &, const TicTacToe &);
    bool setValues(int, int, char);
    bool Win(char);
    bool Draw();
};
TicTacToe::TicTacToe()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = '-';
        }
    }
}
ostream &operator<<(ostream &output, const TicTacToe &t)
{
    output << "-------" << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            output << "|" << t.board[i][j];
        }
        output << "|" << endl;
    }
    output << "-------" << endl;
    return output;
}
bool TicTacToe::setValues(int row, int col, char Player)
{

    if (row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != '-')
    {
        cout << "Invalid move. Try again.\n";
        return false;
    }
    board[row - 1][col - 1] = Player;
    return true;
}

bool TicTacToe::Win(char Player)
{

    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == Player && board[i][1] == Player && board[i][2] == Player)
        {
            return true;
        }
        if (board[0][i] == Player && board[1][i] == Player && board[2][i] == Player)
        {
            return true;
        }
    }
    if (board[0][0] == Player && board[1][1] == Player && board[2][2] == Player)
    {
        return true;
    }
    if (board[0][2] == Player && board[1][1] == Player && board[2][0] == Player)
    {
        return true;
    }
    return false;
}
bool TicTacToe::Draw()
{

    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (board[i][j] == '-')
            {
                return false;
            }
        }
    }
    return true;
}
