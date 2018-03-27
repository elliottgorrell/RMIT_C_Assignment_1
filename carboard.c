/******************************************************************************
** Student name: 	Elliott Gorrell
** Student number: 	s3452258
** Course: 			Advanced Programming Techniques - S1 2018
******************************************************************************/

#include "carboard.h"

int main() {
  int choice = NULL;
  char *buffer;
  Boolean finished = FALSE;

  printf(
  "Welcome to Car Board\n"
  "--------------------\n"
  "1. Play game\n"
  "2. Show student’s information\n"
  "3. Quit\n\n");


  while ( !finished ) {
    printf("Please enter your choice:\n");


    fgets(buffer,10,stdin);
    sscanf(buffer, "%d", &choice);

    clearInputStream(buffer);

    if (choice == 1){
      showGameControls();
      playGame();
    }
    else if (choice == 2){
      showStudentInformation();
    }
    else if (choice == 3){
      finished = TRUE;
    }

    printf("\n");

  }

  printf("Good bye! \n\n");

  return EXIT_SUCCESS;
}

void showStudentInformation() {
    printf("----------------------------------\n");
    printf("Name: %s\n", STUDENT_NAME);
    printf("Name: %s\n", STUDENT_ID);
    printf("Name: %s\n", STUDENT_EMAIL);
    printf("----------------------------------\n");
}

void showGameControls() {
  printf(
    "You can use the following commands to play the game:\n"
    "load <g>\n"
    "\tg: number of the game board to load\n"
    "init <x>,<y>,<direction>\n"
    "\tx: horizontal position of the car on the board (between 0 & 9)\n"
    "\ty: vertical position of the car on the board (between 0 & 9)\n"
    "\tdirection: direction of the car’s movement (north, east, south, west)\n"
    "forward (or f)\n"
    "turn_left (or l)\n"
    "turn_right (or r)\n"
    "quit\n");
}
