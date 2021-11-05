#ifndef FIND_WALDO_H_
#define FIND_WALDO_H_

#define DEBUG


#define DEBUG_COL 5
#define DEBUG_ROW 5

#define HINT_ROW_INPUT (-1)
#define HINT_COL_INPUT (-1)

#define MAX_COLS 10
#define MAX_ROWS 10


#define MAX_ROUNDS 10


extern int gWaldoColumn;
extern int gWaldoRow;




int hideWaldoAtColumn();

int hideWaldoAtRow();


int isWaldoAt(char world[][MAX_COLS], int row, int column);

void printWorld(char world[][MAX_COLS]);

void resetWorld(char world[][MAX_COLS]);

#endif 
