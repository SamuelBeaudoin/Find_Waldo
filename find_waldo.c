
/****************************************************************************************************************
 * Declare include files
 * *************************************************************************************************************/
#include "find_waldo.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int gWaldoColumn;
int gWaldoRow;

int main()
{
    int guess[2];
    int check = 0;
    int found = 0;
    char world[MAX_ROWS][MAX_COLS];
    int attempts = -1;
    int i;

    srand(time(NULL));

    resetWorld(world);

    gWaldoRow = hideWaldoAtRow();
    gWaldoColumn = hideWaldoAtColumn();

    while (1)
    {
        printf("Enter the number of rounds you need to find Waldo (0 to quit; 10 max): ");
        check = scanf("%d", &attempts);
        if (check != 1)
        {
            printf("Error - enter number of rounds between 1 and 10\n");
            while (getchar() != '\n')
                ;
            continue;
        }
        else if (attempts == 0)
        {
            return EXIT_SUCCESS;
        }
        else if (attempts < 1 || attempts > 10)
        {
            printf("Error - enter number of rounds between 1 and 10\n");
            while (getchar() != '\n')
                ;
            continue;
        }
        else
        {
            printWorld(world);
            break;
        }
    }
    while (getchar() != '\n')
        ;

    for (i = 1; i <= attempts; i++)
    {
        while (1)
        {
            printf("\nRound %d of %d. Enter row and column (control-d to quit): ", i, attempts);
            check = scanf("%d %d", &guess[0], &guess[1]);
            if (check == EOF)
            {
                printf("\n");
                return EXIT_FAILURE;
            }
            else if (check != 2)
            {
                printf("Error - enter a row (int) and column (int).\n");
                while (getchar() != '\n')
                    ;
                continue;
            }
            else if (guess[0] == -1 && guess[1] == -1)
            {
                break;
            }
            else if (guess[0] < 1 || guess[0] > 10)
            {
                printf("Error - row must be in range 1 to 10\n");
                while (getchar() != '\n')
                    ;
                continue;
            }
            else if (guess[1] < 1 || guess[1] > 10)
            {
                printf("Error - column must be in range 1 to 10\n");
                while (getchar() != '\n')
                    ;
                continue;
            }
            else
            {
                break;
            }
        }

        if (guess[0] == -1 && guess[1] == -1)
        {
            printf("Hint: %d %d\n", gWaldoRow, gWaldoColumn);
            i--;
        }
        else
        {
            found = isWaldoAt(world, guess[0], guess[1]);
            printWorld(world);
            if (found == 1)
            {
                printf("Huzzah... you found Waldo!\n");
                return EXIT_SUCCESS;
            }
            else
            {
                printf("Miss!\n");
            }
        }
    }
    printf("LOST - you can't find Waldo in %d round like you said.\n", attempts);
    return EXIT_FAILURE;
}

/**********************************************************************************************************
 * Function name: hideWaldoAtColumn
 * Purpose: hides waldo at a random column
 * Function In parameters: nothing
 * Function Out parameters: returns the column at which it is hidden
 * Version: 1
 * Author/Student Name: Samuel Beaudoin
 * 
 * ********************************************************************************************************/
int hideWaldoAtColumn()
{
#ifdef DEBUG
    return DEBUG_COL;
#else
    return rand() % (MAX_COLS - 1) + 1;
#endif
}

/**********************************************************************************************************
 * Function name: hideWaldoAtRow
 * Purpose: Hide waldo at a random row
 * Function In parameters: nothing
 * Function Out parameters: returns the row at which it is hidden
 * Version: 1
 * Author/Student Name: Samuel Beaudoin
 * 
 * ********************************************************************************************************/
int hideWaldoAtRow()
{
#ifdef DEBUG
    return DEBUG_ROW;
#else
    return rand() % (MAX_ROWS - 1) + 1;
#endif
}

/**********************************************************************************************************
 * Function name: isWaldoAt
 * Purpose: Check if the guess matches the place where waldo is and set either m or w
 * Function In parameters: passing in the 2D array and the colum and row for the guess
 * Function Out parameters: returns 1 or 0 according to if it find waldo or not
 * Version: 1
 * Author/Student Name: Samuel Beaudoin
 * 
 * ********************************************************************************************************/
int isWaldoAt(char world[][MAX_COLS], int row, int column)
{
    if (row == gWaldoRow && column == gWaldoColumn)
    {
        world[row - 1][column - 1] = 'W';
        return 1;
    }
    else
    {
        world[row - 1][column - 1] = 'm';
        return 0;
    }
}

/**********************************************************************************************************
 * Function name: printWorld
 * Purpose: Print out the world to the console
 * Function In parameters: passing in the 2D array
 * Function Out parameters: void
 * Version: 1
 * Author/Student Name: Samuel Beaudoin
 * 
 * ********************************************************************************************************/
void printWorld(char world[][MAX_COLS])
{
    int c;
    int r;

    for (r = -1; r < MAX_ROWS; r++)
    {
        if (r >= 0)
        {
            printf("%2d ", (r + 1));
        }
        else
        {
            printf("   ");
        }
        for (c = 0; c < MAX_COLS; c++)
        {
            if (r >= 0)
            {
                printf(" %c ", world[r][c]);
            }
            else
            {
                printf(" %d ", c + 1);
            }
        }
        printf("\n");
    }
}

/**********************************************************************************************************
 * Function name: resetWorld
 * Purpose: Resets the world to all * everywhere in the 2D array
 * Function In parameters: passing in the 2D array
 * Function Out parameters: void
 * Version: 1
 * Author/Student Name: Samuel Beaudoin
 * 
 * ********************************************************************************************************/
void resetWorld(char world[][MAX_COLS])
{
    int c;
    int r;

    for (r = 0; r < MAX_ROWS; r++)
    {
        for (c = 0; c < MAX_COLS; c++)
        {
            world[r][c] = '*';
        }
    }
}
