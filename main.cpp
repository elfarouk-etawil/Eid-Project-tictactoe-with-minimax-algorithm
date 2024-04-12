#include <iostream>

using namespace std;

typedef char Board[3][3];

struct position
{
    short i;
    short j;
};

#include "board.h"
#include "computer.h"

int main()
{
    system("color 3");
    // Welcome the user
    cout << "\t-<Welcome to tic tac toe>-" << endl;
    cout << "\tTry to defeat the computer\n" << endl;
    cout << "Press Enter to continue...";
    cin.get();
    system("cls");

    // Print instructions
    cout << "Instructions: \n"
    << "1. You starts first!\n"
    << "2. Use number from 1 to 9 to select your next move!\n"
    << "Good luck!\n\n";
    cout << "Press Enter to continue...";
    cin.get();
    system("cls");

    Board board;
    Computer comp;
    reset_board(board);

    while(get_winner(board) == ' ' && space_count(board) > 0)
    {
        system("color 6");
        display_board(board);
        short next_move;
        while(true)
        {
            cout << "Enter Your Move(1-9): ";
            cin >> next_move;
            cin.clear();

            if (next_move > 9 || next_move < 1)
                continue;

            position pos = get_position(next_move);
            if (board[pos.i][pos.j] != ' ')
                continue;

            update_board(board, pos, 'X');
            break;
        }

        display_board(board);
        if (get_winner(board) != ' ') break;

        comp.next_move(board);
        display_board(board);
    }

    cout << endl;
    char winner = get_winner(board);
    if (winner == 'X') cout << "YOU WON!\n";
    else if (winner == 'O') cout << "COMPUTER WON!\n";
    else cout << "TIE!\n";

    return 0;
}
