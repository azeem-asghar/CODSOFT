#include <iostream>
#include "TicTacToe.h"

#include <stdlib.h>

using namespace std;
int main()
{
    int choice;

    int row, col;
    do
    {

        bool game = false;
        TicTacToe t;
        char Player = 'X';

        while (!game)
        {
            system("CLS");
            cout << t;

            cout << "Player " << Player << "'s turn." << endl;
            cout << "Enter row:";
            cin >> row;
            cout << "Enter col:";
            cin >> col;

            if (t.setValues(row, col, Player))
            {
                if (t.Win(Player))
                {
                    cout << t;
                    cout << "Player " << Player << " wins!\n";

                    game = true;
                    cout << "Do you want to play again?\nPress 1 to play:";
                    cin >> choice;
                }
                else if (t.Draw())
                {
                    cout << t;
                    cout << "Game drawn!\n";

                    game = true;
                    cout << "Do you want to play again?\nPress 1 to play:";
                    cin >> choice;
                }
                else
                {
                    if (Player == 'X')
                    {
                        Player = 'O';
                    }
                    else
                    {
                        Player = 'X';
                    }
                }
            }
        }

    } while (choice == 1);
}