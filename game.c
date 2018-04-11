/******************************************************************************
** Student name: 	Elliott Gorrell
** Student number: 	s3452258
** Course: 			Advanced Programming Techniques - S1 2018
******************************************************************************/

#include "game.h"

char buffer[20];
char tmpBuffer[20];
char *command= NULL;
char *token = NULL;
char *arg1 = NULL;
char *arg2 = NULL;
char *arg3 = NULL;

void playGame()
{
    Cell board[BOARD_HEIGHT][BOARD_WIDTH];
    /* Allow args in command to be seperated with a space or comma */
    char delimiter[] = ", \n";
    Boolean finished = FALSE;

    initialiseBoard(board);
    displayBoard(board, NULL);



    while ( !finished ) {
      printf("What you wanna do:\n");

      fgets(buffer,20,stdin);
      strcpy(&tmpBuffer, &buffer);

      command = strtok(tmpBuffer,delimiter);

      if (strcmp(command, COMMAND_LOAD) == 0) {
        arg1 = strtok(NULL, delimiter);

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

      else if (strcmp(command, COMMAND_INIT) == 0) {
        arg1 = strtok(NULL, delimiter);
        arg2 = strtok(NULL, delimiter);
        arg3 = strtok(NULL, delimiter);

        printf("x: %s, y: %s, direction: %s",arg1,arg2,arg3);

        if (arg1 == NULL || arg2 == NULL || arg3 == NULL) {
          printf("input for 'init' command must be in the format 'init x,y,direction' or 'init x y direction' ");
        }

        else{
          int x = atoi(arg1);
          int y = atoi(arg2);
          char *direction = arg3;

          printf("x: %d, y: %d, direction: %s",x,y,direction);
        }
      }

      else if (strcmp(command, "quit") == 0) {
        printf("Sending you back to the main menu...\n\n");
        finished = TRUE;
      }

      else {
        printf("Invalid Command\n");
      }

      clearInputStream(buffer);
      clearGlobals();


    }
}

void clearGlobals(){
  memset(&buffer[0], 0, sizeof(buffer));
  if (command) memset(&command[0], 0, sizeof(command));
  if (arg1) memset(&arg1[0], 0, sizeof(arg1));
  if (arg2) memset(&arg2[0], 0, sizeof(arg2));
  if (arg3) memset(&arg3[0], 0, sizeof(arg3));
}
