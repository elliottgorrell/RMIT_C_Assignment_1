/******************************************************************************
** Student name: 	Elliott Gorrell
** Student number: 	s3452258
** Course: 			Advanced Programming Techniques - S1 2018
******************************************************************************/

#include "board.h"

Cell BOARD_1[BOARD_HEIGHT][BOARD_WIDTH] =
{
    { BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY },
    { EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, BLOCKED, EMPTY, BLOCKED, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED }
};

Cell BOARD_2[BOARD_HEIGHT][BOARD_WIDTH] =
{
    { BLOCKED, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY }
};

void initialiseBoard(Cell board[BOARD_HEIGHT][BOARD_WIDTH])
{
  int y,x;
  for (y=0; y < BOARD_HEIGHT; y++) {
    for (x=0; x < BOARD_WIDTH; x++){
      board[y][x] = EMPTY;
    }
  }
}

void loadBoard(Cell board[BOARD_HEIGHT][BOARD_WIDTH],
               Cell boardToLoad[BOARD_HEIGHT][BOARD_WIDTH])
{
  int y,x;
  for (y=0; y < BOARD_HEIGHT; y++) {
    for (x=0; x < BOARD_WIDTH; x++){
      board[y][x] = boardToLoad[y][x];
    }
  }
}

Boolean placePlayer(Cell board[BOARD_HEIGHT][BOARD_WIDTH], Position position)
{
    if (board[position.y][position.x] != EMPTY) {
      return FALSE;
    }

    board[position.y][position.x] = PLAYER;
    return TRUE;
}

PlayerMove movePlayerForward(Cell board[BOARD_HEIGHT][BOARD_WIDTH], Player * player)
{
    Position newPosition = getNextForwardPosition(player);


    if (newPosition.x <0 || newPosition.x > (BOARD_WIDTH-1) || newPosition.y > (BOARD_HEIGHT-1) || newPosition.y < 0 ){
      return OUTSIDE_BOUNDS;
    }

    else if ( board[newPosition.y][newPosition.x] == BLOCKED) {
      return CELL_BLOCKED;
    }

    else {
      board[newPosition.y][newPosition.x] = PLAYER;
      updatePosition(player, newPosition);
      return PLAYER_MOVED;
    }

}

void displayBoard(Cell board[BOARD_HEIGHT][BOARD_WIDTH], Player * player)
{
  int y,x;
  for (y=-1; y < BOARD_HEIGHT; y++) {
    for (x=-1; x < BOARD_WIDTH; x++){
      printf("|");

      if(x == -1 && y == -1) {
        printf(EMPTY_OUTPUT);
      }

      else if(y == -1) {
        printf("%d",x);
      }

      else if(x == -1) {
        printf("%d",y);
      }

      else {
        Cell state = board[y][x];
        if (state == EMPTY) {
          printf(EMPTY_OUTPUT);
        }
        if (state == PLAYER) {
          displayDirection(player->direction);
        }
        else if(state == BLOCKED){
          printf(BLOCKED_OUTPUT);
        }
      }

    }
    printf("|");
    printf("\n");
  }
  printf("\n");

}
