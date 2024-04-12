#ifndef COMPUTER_H
#define COMPUTER_H

// Class definition for the computer player
class Computer
{
public:
    // Function to determine the computer's next move
    void next_move(Board& b);

private:
    // Recursive function to implement the minimax algorithm
    int minimax(Board& b, bool maximizing);
};

// Function to determine the computer's next move
void Computer::next_move(Board& b)
{
    position move;
    int maxval = -1000;
    // Iterate over each empty position on the board
    for (size_t i = 0; i < 3; i++)
        for (size_t j = 0; j < 3; j++)
        {
            if (b[i][j] == ' ')
            {
                // Try placing the computer's symbol ('O') at the current position
                b[i][j] = 'O';
                // Call minimax recursively to evaluate the resulting board state
                int currentval = minimax(b, false);
                // Update maxval if the current value is greater
                if (currentval > maxval)
                {
                    maxval = currentval;
                    move = {i, j};
                }
                // Undo the move to explore other possibilities
                b[i][j] = ' ';
            }
        }
    // Update the board with the best move found
    update_board(b, move, 'O');
}

// Recursive function to implement the minimax algorithm
int Computer::minimax(Board& b, bool maximizing)
{
    // Evaluate the current state of the board
    short score = evaluate(b);
    // If the game is over or there are no more empty spaces, return the score
    if(score || !space_count(b)) return score;

    if (maximizing) // If maximizing player (computer)
    {
        int maxval = -1000;
        // Iterate over each empty position on the board
        for (size_t i = 0; i < 3; i++)
            for (size_t j = 0; j < 3; j++)
            {
                if (b[i][j] == ' ')
                {
                    // Try placing the computer's symbol ('O') at the current position
                    b[i][j] = 'O';
                    // Recursively call minimax with the opponent's turn (minimizing player)
                    maxval = max(maxval, minimax(b, false));
                    // Undo the move to explore other possibilities
                    b[i][j] = ' ';
                }
            }
        // Return the maximum value found
        return maxval;
    }
    else // If minimizing player (opponent)
    {
        int minval = 1000;
        // Iterate over each empty position on the board
        for (size_t i = 0; i < 3; i++)
            for (size_t j = 0; j < 3; j++)
            {
                if (b[i][j] == ' ')
                {
                    // Try placing the opponent's symbol ('X') at the current position
                    b[i][j] = 'X';
                    // Recursively call minimax with the computer's turn (maximizing player)
                    minval = min(minimax(b, true), minval);
                    // Undo the move to explore other possibilities
                    b[i][j] = ' ';
                }
            }
        // Return the minimum value found
        return minval;
    }
}

#endif // COMPUTER_H
