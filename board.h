#ifndef BOARD_H
#define BOARD_H

// Function to reset the board to its initial state
void reset_board(Board &b)
{
    for (size_t i = 0; i < 3; i++)
        for (size_t j = 0; j < 3; j++)
            b[i][j] = ' ';
}

// Function to convert a move number to its corresponding position on the board
inline position get_position(short n)
{
    return {(n-1)/3, (n-1)%3};
}

// Function to display the current state of the game board
void display_board(const Board b)
{
    system("cls"); // Clear the console screen
    cout << "+---+---+---+" << endl;
    cout << "| " << b[0][0] << " | " << b[0][1] << " | " << b[0][2] << " |" << endl;
    cout << "+---+---+---+" << endl;
    cout << "| " << b[1][0] << " | " << b[1][1] << " | " << b[1][2] << " |" << endl;
    cout << "+---+---+---+" << endl;
    cout << "| " << b[2][0] << " | " << b[2][1] << " | " << b[2][2] << " |" << endl;
    cout << "+---+---+---+" << endl;
}

// Function to update the board with a player's move
inline void update_board(Board& b, position p, char c)
{
    b[p.i][p.j] = c;
}

// Function to count the number of empty spaces on the board
uint16_t space_count(Board& b)
{
    uint16_t cnt = 0;
    for (int i = 0; i < 3; i++)
        for (int j =0; j < 3; j++)
            if (b[i][j] == ' ') cnt++;
    return cnt;
}

// Function to determine the winner of the game
char get_winner(Board& b)
{
    char winner = ' ';
    for (int i = 0; i < 3; i++)
        if (b[i][0] == b[i][1] && b[i][1] == b[i][2])
            winner = b[i][0];

    for (int j = 0; j < 3; j++)
        if (b[0][j] == b[1][j] && b[1][j] == b[2][j])
            winner = b[0][j];

    if (b[0][0] == b[1][1] && b[1][1] == b[2][2])
        winner = b[1][1];

    if (b[0][2] == b[1][1] && b[1][1] == b[2][0])
        winner = b[1][1];

    return winner;
}

// Function to evaluate the current state of the board
short evaluate(Board& board)
{
    switch (get_winner(board))
    {
    case ' ': return 0; // If the game is still ongoing
    case 'X': return -1; // If the player wins
    case 'O': return 1;  // If the computer wins
    }
}

#endif // BOARD_H
