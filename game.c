/******************************************************************************
** Student name: 	Elliott Gorrell
** Student number: 	s3452258
** Course: 			Advanced Programming Techniques - S1 2018
******************************************************************************/

#include "game.h"

void playGame()
{
    Cell board[BOARD_HEIGHT][BOARD_WIDTH];

    char buffer[20];
    char command[10];
    char *token;
    char arg1[3];
    char arg2[3];
    char arg3[10];
    Boolean finished = FALSE;

    /* TODO */
    /**
     * This is some sample code using the functions provided.
     *
     * Note that NULL is passed as the "Player * player" parameter as there is
     * no player cell present on the board in this example.
     */
    initialiseBoard(board);
    displayBoard(board, NULL);



    while ( !finished ) {
      printf("What you wanna do:\n");
      fgets(buffer, 20, stdin);

      token = strtok(buffer," ");
      strncpy(command, token, strlen(token));

      if (strcmp("quit", command) == 0){
        printf("User quit");
      }

      else if (strcmp("load", command) == 0){
        token = strtok(NULL, ",");
        if (strlen(token) > 1){
          incorrectInput();
        }
        else{
          strncpy(arg1, token, strlen(token));
          loadBoard(board, BOARD_1);
          displayBoard(board, NULL);
        }
      }

      else if (strcmp("init", command) == 0){
        token = strtok(NULL, ",");
        if (strlen(token) > 1){
          incorrectInput();
        }
        else {
          strncpy(arg1, token, strlen(token));
        }

        token = strtok(NULL, ",");
        if (strlen(token) > 1){
          incorrectInput();
        }
        else {
          strncpy(arg2, token, strlen(token));
        }

        token = strtok(NULL, ",");
        strncpy(arg3, token, 10);
      }







      printf("%s %s %s %s\n",command, arg1, arg2, arg3);

      memset(&buffer[0], 0, sizeof(buffer));
      memset(&token[0], 0, sizeof(token));
      memset(&arg1[0], 0, sizeof(arg1));
      memset(&arg2[0], 0, sizeof(arg2));
      memset(&arg3[0], 0, sizeof(arg3));

    }

    loadBoard(board, BOARD_1);
    displayBoard(board, NULL);
}

void incorrectInput() {
  printf("INVALID INPUT!\n");
}
