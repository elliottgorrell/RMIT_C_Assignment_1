/******************************************************************************
** Student name: 	Elliott Gorrell
** Student number: 	s3452258
** Course: 			Advanced Programming Techniques - S1 2018
******************************************************************************/

#include "game.h"

void playGame()
{
    Cell board[BOARD_HEIGHT][BOARD_WIDTH];
    Player player;

    Boolean finished = FALSE;

    char buffer[15];
    char tmpBuffer[15];
    char * command;

    initialiseBoard(board);

    Boolean completedSetup = setupGame(&player, board);

    play_game: while ( !finished ) {
      printf("Make a move:\n");

      fgets(buffer,15,stdin);
      strncpy(tmpBuffer, buffer, 15);
      command = strtok(tmpBuffer,"\n\r");

      if (!command) goto play_game;

      if (strcmp(command, COMMAND_FORWARD) == 0 || strcmp(command, COMMAND_FORWARD_SHORTCUT) == 0) {
        printf("TODO");
      }

      else if ( (strcmp(command, COMMAND_TURN_LEFT) == 0) || (strcmp(command, COMMAND_TURN_LEFT_SHORTCUT) == 0) ) {
        turnDirection(&player, TURN_LEFT);
      }

      else if ( (strcmp(command, COMMAND_TURN_RIGHT) == 0) || (strcmp(command, COMMAND_TURN_RIGHT_SHORTCUT) == 0) ) {
        turnDirection(&player, TURN_RIGHT);
      }

      else {
        printf(RED "Invalid Command\n" RESET);
      }

      displayBoard(board, &player);
      printf("%s\n", command);

      clearInputStream(&buffer);

      memset(&buffer[0], 0, sizeof(buffer));
      memset(&tmpBuffer[0], 0, sizeof(tmpBuffer));
      if (command) memset(&command[0], 0, sizeof(command));
    }


}

Boolean setupGame(Player * player, Cell board[BOARD_HEIGHT][BOARD_WIDTH]) {
  /* Allow args in command to be seperated with a space or comma */
  char delimiter[] = ", \n";
  Boolean finished = FALSE;
  Boolean boardLoaded = FALSE;
  Boolean setupComplete = FALSE;

  char buffer[20];
  char tmpBuffer[20];
  char *command= NULL;
  char *arg1 = NULL;
  char *arg2 = NULL;
  char *arg3 = NULL;

  displayBoard(board, NULL);

  run_setup: while ( !finished ) {
    Boolean commandSucceeded = FALSE;
    printf("What you wanna do:\n");

    fgets(buffer,20,stdin);
    strncpy(tmpBuffer, buffer, 20);

    command = strtok(tmpBuffer,delimiter);
    arg1 = strtok(NULL, delimiter);
    arg2 = strtok(NULL, delimiter);
    arg3 = strtok(NULL, delimiter);

    if (!command) goto run_setup;

    if (strcmp(command, COMMAND_LOAD) == 0) {
      commandSucceeded = loadBoardCommand(board, arg1);
      if (commandSucceeded) boardLoaded = TRUE;
    }

    else if (strcmp(command, COMMAND_INIT) == 0) {
      if (!boardLoaded) {
        printf( RED "You need to load a board first\n" RESET);
        goto run_setup;
      }
      commandSucceeded = initBoardCommand(arg1, arg2, arg3, player, board);
      if (commandSucceeded) {
        finished = TRUE;
        setupComplete = TRUE;
      }
    }

    else if (strcmp(command, "quit") == 0) {
      printf("Sending you back to the main menu...\n\n");
      finished = TRUE;
    }

    else {
      printf(RED "Invalid Command\n" RESET);
      commandSucceeded = FALSE;
    }

    if (commandSucceeded) displayBoard(board, player);

    clearInputStream(&buffer);

    memset(&buffer[0], 0, sizeof(buffer));
    if (command) memset(&command[0], 0, sizeof(command));
    if (arg1) memset(&arg1[0], 0, sizeof(arg1));
    if (arg2) memset(&arg2[0], 0, sizeof(arg2));
    if (arg3) memset(&arg3[0], 0, sizeof(arg3));
  }
  return setupComplete;
}

Boolean loadBoardCommand(Cell board[BOARD_HEIGHT][BOARD_WIDTH], char * arg1){
  if (arg1 == NULL) {
    printf(RED "must provide a board number\n" RESET);
    return FALSE;
  }

  /* If we don't have a valid integer we will get returned 0 by atoi so will fall through to else conditional */
  int boardNumber = atoi(arg1);

  if (boardNumber == 1) {
    loadBoard(board, BOARD_1);
  }
  else if (boardNumber == 2) {
    loadBoard(board, BOARD_2);
  }
  else {
    printf(RED "Command must be 'load 1' or 'load 2'\n" RESET);
    return FALSE;
  }

  return TRUE;
}

Boolean initBoardCommand(char * arg1, char * arg2, char * arg3, Player * player, Cell board[BOARD_HEIGHT][BOARD_WIDTH]) {
  if (arg1 == NULL || arg2 == NULL || arg3 == NULL) {
    printf(RED "input for 'init' command must be in the format 'init x,y,direction' or 'init x y direction'\n" RESET);
    return FALSE;
  }

  int x = atoi(arg1);
  int y = atoi(arg2);
  char *direction = arg3;

  Position initialPosition;
  initialPosition.x = x;
  initialPosition.y = y;

  Direction startingDirection;
  if (strcmp(direction, DIRECTION_NORTH) == 0) startingDirection = NORTH;
  else if (strcmp(direction, DIRECTION_SOUTH) == 0) startingDirection = SOUTH;
  else if (strcmp(direction, DIRECTION_EAST) == 0) startingDirection = EAST;
  else if (strcmp(direction, DIRECTION_WEST) == 0) startingDirection = WEST;
  else {
    printf(RED "Direction must be one of: 'north' 'east' 'south' 'west'\n" RESET);
    return FALSE;
  }


  initialisePlayer(player, &initialPosition, startingDirection);
  if ( !placePlayer(board, initialPosition) ) {
    printf(RED "FAILED! You cannot place player at a blocked or out of bound cell!\n" RESET);
    return FALSE;
  }
  return TRUE;
}
