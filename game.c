/******************************************************************************
** Student name: 	Elliott Gorrell
** Student number: 	s3452258
** Course: 			Advanced Programming Techniques - S1 2018
******************************************************************************/

#include "game.h"

char buffer[20];
char *command= NULL;
char *token = NULL;
char *arg1 = NULL;
char *arg2 = 0;
char arg3[10];

void playGame()
{
    Cell board[BOARD_HEIGHT][BOARD_WIDTH];

    Boolean finished = FALSE;

    initialiseBoard(board);
    displayBoard(board, NULL);



    while ( !finished ) {
      printf("What you wanna do:\n");
      fgets(buffer,20,stdin);
      command = strtok(buffer," ");


      if (strcmp(command, COMMAND_LOAD) == 0) {
        arg1 = strtok(NULL, " ");

        /* If we don't have a valid integer we will get returned 0 by atoi so will fall through to else conditional */
        int boardNumber = atoi(arg1);

        if (boardNumber == 1) {
          loadBoard(board, BOARD_1);
          displayBoard(board, NULL);
        }
        else if (boardNumber == 2) {
          loadBoard(board, BOARD_2);
          displayBoard(board, NULL);
        }
        else {
          printf("Command must be 'load 1' or 'load 2'\n");
        }
      }




      else {
        printf("Invalid Command\n");
      }

      clearGlobals();
      clearInputStream(buffer);

    }
}

void clearGlobals(){
  memset(&buffer[0], 0, sizeof(buffer));
  if (command) memset(&command[0], 0, sizeof(command));
  if (arg1) memset(&arg1[0], 0, sizeof(arg1));
  if (arg2) memset(&arg2[0], 0, sizeof(arg2));
  if (arg3) memset(&arg3[0], 0, sizeof(arg3));
}
