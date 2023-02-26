#include <stdio.h>
#include <stdlib.h>

#define SIZE 8

// global variables
char board[SIZE][SIZE];
int white, black, free_cell = 64;

// functions
void gameloop();
void help();
void create_board();
void draw();
void insert(char player, char row, char column);
int occupied(char row, char column);
void reset();
int is_placeable(char player, char row, char column);
void show_placeable(char player);
void apply_changes(char player, char opponent, char row, char column);
void update_scores();
void display_scores();
void gameover();

void gameloop()
{
    help();

    create_board();

    int turn = 0;
    while(free_cell != 0)
    {
        // show placeable positions on board
        show_placeable((turn % 2) == 0 ? 'B' : 'W');
        draw();

        // display scores
        update_scores();
        display_scores();

        printf("player %d its your turn\n",(turn % 2) + 1);

        char block[2];
        printf("choose a block : ");
        scanf("%s", &block);

        char player, oponent;
        player = (turn % 2) == 0 ? 'W' : 'B';
        oponent = player == 'W' ? 'B' : 'W';
        // if the cell is empty and placeable insert
        if (occupied(block[0], block[1]) == 0)
        {
            insert(player, block[0], block[1]);
            apply_changes(player, oponent, block[0], block[1]);
            turn++;
        }
        else
        {
            printf("wrong move! try again.\n");
        }

        // remove the * from board
        reset();
    }

    gameover();
}

/*
 * prints a help message for new players
 */
void help()
{
    char *text = "The object of the game Othello is to win!\n\nThe game gets its name from Shakespeare's Othello, who kept changing\nfrom bad to good and back again --from white to black, back and forth.\n. There are two\nplayers: white and black. White goes first, by placing a piece in some\nempty square (do this by clicking the mouse in the square in which you\n want to place a piece). However, you can't place a white piece in just\nany square, but only in one that satisfies the following condition:\n\n     In at least one direction (vertical, horizontal, or diagonal) emanating\n     from the square, there is a sequence of one or more black pieces\n     followed by a white piece.\n\nWhen a white piece is placed in such a square, all the black pieces\nmentioned in this condition become white --in all directions. Try it!\n\nAfter a white piece is placed, the other player places a black piece in the\nsame manner (with the roles of white and black interchanged). Then it's\nwhite's turn again, an so it goes.\n\nA player who cannot place a piece loses their turn. If no player can play,\nthe game is over, and the player with the most pieces wins.";

    printf("%s\npress any key to start",text);
    getchar();
}

void create_board()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            board[i][j] = '_';
        }
    }

    insert('W', '4', 'D');
    insert('W', '5', 'E');
    insert('B', '4', 'E');
    insert('B', '5', 'D');
}

void draw()
{
    // row names display
    printf("   ");
    for (int i = 0; i < SIZE; i++)
    {
        printf(" %c ", i+65);
    }
    printf("\n");

    // board display
    for (int i = 0; i < SIZE; i++)
    {
        // column names display
        printf(" %i ",i+1);
        for (int j = 0; j < SIZE; j++)
        {
            printf(" %c ", board[i][j]);
        }
        printf("\n");
    }
}

void insert(char player, char row, char column)
{
    // change ascii code to places in matrix
    // its 49 and not 48 becaus arrays start with 0 not 1
    board[row - 49][column - 65] = player;
}

/*
 * if the given block is empty return zero
 * else return 1
 */
int occupied(char row, char column)
{
    return board[row - 49][column - 65] == '*' ? 0 : 1;
}

/*
 * return true if the given block is near other B/W blocks
 * else return false
 */
int is_placeable(char player, char row, char column)
{
    row = row + 48;
    column = column + 65;
    if (board[row - 48][column - 66] == player ||
        board[row - 48][column - 64] == player ||
        board[row - 49][column - 65] == player ||
        board[row - 47][column - 65] == player)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/*
 * draw an '*' in places where you can have your next move
 */
void show_placeable(char player)
{
   //complete this function.
   //use "is_placeable" function


}

void reset()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (board[i][j] == '*')
            {
                board[i][j] = '_';
            }
        }
    }
}

/*
 * after inserting a point for your next move
 * this function apply changes in the game
 * and flip color of peaces which have the condition
 */
void apply_changes(char player, char opponent, char row, char column)
{
    int i = row - 49, j = column-65;
    int x = i, y = j;

    if (i - 1 >= 0 && j - i >= 0 && board[i - 1][j - 1] == opponent)
    {
        i--;
        j--;
        while(i > 0 && j > 0 && board[i][j] == opponent)
        {
            i--;
            j--;
        }
        if(i >= 0 && j >= 0 && board[i][j] == player)
        {
            while(i != x - 1 && j != y - 1)
                board[++i][++j]=player;
        }
    }

    i = x;
    j = y;

    if(i - 1 >= 0 && board[i - 1][j] == opponent){
        i--;
        while(i > 0 && board[i][j] == opponent)
            i--;
        if(i >= 0 && board[i][j] == player)
        {
            while(i != x - 1)
                board[++i][j]=player;
        }
    }

    i = x;
    
    if(i - 1 >= 0 && j + 1 <= 7 && board[i - 1][j + 1] == opponent){
        i--;
        j++;
        while(i > 0 && j < 7 && board[i][j] == opponent)
        {
            i--;
            j++;
        }
        if(i >= 0 && j <= 7 && board[i][j] == player)
        {
            while(i != x - 1 && j != y + 1)
                board[++i][--j] = player;
        }
    }

    i = x;
    j = y;
    
    if(j - 1 >= 0 && board[i][j - 1] == opponent){
        j--;
        while(j > 0 && board[i][j] == opponent)
            j--;
        if(j >= 0 && board[i][j] == player)
        {
            while(j != y - 1)
                board[i][++j] = player;
        }
    }

    j = y;

    if(j + 1 <= 7 && board[i][j + 1] == opponent){
        j++;
        while(j < 7 && board[i][j] == opponent)
            j++;
        if(j <= 7 && board[i][j] == player)
        {
            while(j != y + 1)
                board[i][--j] = player;
        }
    }

    j = y;

    if(i + 1 <= 7 && j - 1 >= 0 && board[i + 1][j - 1] == opponent){
        i++;
        j--;
        while(i < 7 && j > 0 && board[i][j] == opponent)
        {
            i++;
            j--;
        }
        if(i <= 7 && j >= 0 && board[i][j] == player)
        {
            while(i != x + 1 && j != y - 1)
                board[--i][++j] = player;
        }
    }

    i = x;
    j = y;
    //==================================
    // complete two other conditions.



    //==================================
    // complete two other conditions.



}

void update_scores()
{
    // reset scores
    black = 0, white = 0, free_cell = 64;
    // complete ................


}

void display_scores()
{
    printf("      BLACK %d - WHITE %d\n", black, white);
}

void gameover()
{
    if (black > white)
    {
        printf("BLACK TEAM WINS!\n");
    }
    else if (black < white)
    {
        printf("WHITE TEAM WINS!\n");
    }
    else
    {
        printf("DRAW!\n");
    }
    display_scores();
}

int main()
{
    gameloop();
    return 0;
}