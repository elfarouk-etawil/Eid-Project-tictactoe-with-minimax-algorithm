#ifndef BOARD_H
#define BOARD_H

void reset_board(Board &b)
{
    for (size_t i = 0; i < 3; i++)
        for (size_t j = 0; j < 3; j++)
            b[i][j] = ' ';
}

inline position get_position(short n)
{
    return {(n-1)/3, (n-1)%3};
}


void display_board(const Board b)
{
    system("cls");
    cout << "+---+---+---+" << endl;
    cout << "| " << b[0][0] << " | " << b[0][1] << " | " << b[0][2] << " |" << endl;
    cout << "+---+---+---+" << endl;
    cout << "| " << b[1][0] << " | " << b[1][1] << " | " << b[1][2] << " |" << endl;
    cout << "+---+---+---+" << endl;
    cout << "| " << b[2][0] << " | " << b[2][1] << " | " << b[2][2] << " |" << endl;
    cout << "+---+---+---+" << endl;
}

inline void update_board(Board& b, position p, char c)
{
    b[p.i][p.j] = c;
}

uint16_t space_count(Board& b)
{
    uint16_t cnt = 0;
    for (int i = 0; i < 3; i++)
        for (int j =0; j < 3; j++)
            if (b[i][j] == ' ') cnt++;
    return cnt;
}

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

short evaluate(Board& board)
{
    switch (get_winner(board))
    {
    case ' ': return 0;
    case 'X': return -1;
    case 'O': return 1;
    }
}


#endif // BOARD_H
