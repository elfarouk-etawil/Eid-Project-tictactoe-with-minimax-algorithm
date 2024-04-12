#ifndef COMPUTER_H
#define COMPUTER_H

class Computer
{
public:
    void next_move(Board& b);
private:
    int minimax(Board& b, bool maximizing);

};

void Computer::next_move(Board& b)
{
    position move;
    int maxval = -1000;
    for (size_t i = 0; i < 3; i++)
        for (size_t j = 0; j < 3; j++)
        {
            if (b[i][j] == ' ')
            {
                b[i][j] = 'O';
                int currentval = minimax(b, false);
                if (currentval > maxval)
                {
                    maxval = currentval;
                    move = {i, j};
                }
                b[i][j] = ' ';
            }
        }
    update_board(b, move, 'O');
}

int Computer::minimax(Board& b, bool maximizing)
{
    short score = evaluate(b);
    if(score || !space_count(b)) return score;

    if (maximizing)
    {
        int maxval = -1000;
        for (size_t i = 0; i < 3; i++)
            for (size_t j = 0; j < 3; j++)
            {
                if (b[i][j] == ' ')
                {
                    b[i][j] = 'O';
                    maxval = max(maxval, minimax(b, false));
                    b[i][j] = ' ';
                }
            }
        return maxval;
    }
    else
    {
        int minval = 1000;
        for (size_t i = 0; i < 3; i++)
            for (size_t j = 0; j < 3; j++)
            {
                if (b[i][j] == ' ')
                {
                    b[i][j] = 'X';
                    minval = min(minimax(b, true), minval);
                    b[i][j] = ' ';
                }
            }
        return minval;
    }
}
#endif // COMPUTER_H
