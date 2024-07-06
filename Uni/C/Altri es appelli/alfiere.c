
void init_board(int board[8][8])
{
    for (int i = 0; i < 8; i++)
    {
        for (int n = 0; n < 8; n++)
        {
            board[i][n] = 0;
        }
    }
}

void print_board(int board[8][8])
{
    for (int i = 0; i < 8; i++)
    {
        for (int n = 0; n < 8; n++)
        {
            printf("%d ", board[i][n]);
        }
        printf("\n");
    }
}

void mossa_alfiere(int *board[8][8], int x, int y)
{
    int count = 0;
    if (x - count >= 0 && x + count < 8 && y - count >= 0 && y + count < 8)
    {
    }
    else
        return;
    while (x - count >= 0 || x + count < 8 || y - count >= 0 || y + count < 8)
    {
        if (x - count >= 0)
        {
            if (y - count >= 0)
            {

                board[x - count][y - count] = 1;
            }
            if (y + count < 8)
            {

                board[x - count][y + count] = 1;
            }
        }
        if (x + count < 8)
        {

            if (y - count >= 0)
            {
                board[x + count][y - count] = 1;
            }
            if (y + count < 8)
            {

                board[x + count][y + count] = 1;
            }
        }
        count++;
    }
}

int main()
{
    int board[8][8];
    init_board(board);

    mossa_alfiere(board, 7, 0);
    print_board(board);

    return 0;
}