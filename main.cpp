#include <iostream>

using namespace std;

typedef char Board[3][3]; // Define a 3x3 board using a two-dimensional array of characters

struct position
{
    short i; // Row index
    short j; // Column index
};

#include "board.h"
#include "computer.h"

int main()
{
    // Welcome the user
    system("color 3"); // Set console text to aqua
    cout << "\t-<Welcome to tic tac toe>-" << endl;
    cout << "\tTry to defeat the computer\n" << endl;
    cout << "Press Enter to continue...";
    cin.get(); // Wait for user to press Enter
    system("cls"); // Clear the console screen

    // Print game instructions
    cout << "Instructions: \n"
    << "1. You start first!\n"
    << "2. Use numbers from 1 to 9 to select your next move!\n"
    << "Good luck!\n\n";
    cout << "Press Enter to continue...";
    cin.get(); // Wait for user to press Enter
    system("cls"); // Clear the console screen

    Board board;
    Computer comp;

    game_start: // Label used for restarting the game
    reset_board(board); // Reset the game board to its initial state
    while(get_winner(board) == ' ' && space_count(board) > 0) // Continue game until there is a winner or the board is full
    {
        system("color 6"); // Set console text to yellow
        display_board(board); // Display the current state of the game board
        short next_move;
        while(true) // Loop until a valid move is entered
        {
            cout << "Enter Your Move(1-9): ";
            cin >> next_move;
            cin.clear(); // Clear any error flags

            if (next_move > 9 || next_move < 1) // If move is out of range
                continue; // Continue to prompt for input

            position pos = get_position(next_move); // Get the position on the board corresponding to the entered move
            if (board[pos.i][pos.j] != ' ') // If the chosen position is already occupied
                continue; // Continue to prompt for input

            update_board(board, pos, 'X'); // Update the board with the player's move
            break;
        }

        display_board(board);
        if (get_winner(board) != ' ') break; // If there's a winner, exit the loop

        comp.next_move(board); // Computer calculates and makes its move
        display_board(board);
    }

    cout << endl;
    char winner = get_winner(board);
    if (winner == 'X') cout << "YOU WON!\n";
    else if (winner == 'O') cout << "COMPUTER WON!\n";
    else cout << "TIE!\n";

    cout << endl;
    char response;
    cout << "Do you want to start a new game?(Y/N): ";
    cin >> response;
    cin.clear(); // Clear any error flags

    if (response == 'y' || response == 'Ý') goto game_start; // If user wants to start a new game, jump to the game_start label

    system("cls");
    system("color 7"); // Set console text to white
    cout << "GOOD BYE!... ";
    cout << endl;

    return 0;
}
