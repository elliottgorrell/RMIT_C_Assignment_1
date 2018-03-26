/******************************************************************************
** Student name: 	Elliott Gorrell
** Student number: 	s3452258
** Course: 			Advanced Programming Techniques - S1 2018
******************************************************************************/

#include "carboard.h"

int main()
{
  printf(
  "Welcome to Car Board\n"
  "--------------------\n"
  "1. Play game\n"
  "2. Show student’s information\n"
  "3. Quit\n\n");

  char choice[1];
  int finished = 0;

  while ( !finished ){
    printf("Please enter your choice:\n");

    scanf("%s",&choice);

    if (choice[0] == '1'){
      printf("Not yet implemented\n");
    }
    else if (choice[0] == '2'){
      showStudentInformation();
    }
    else if (choice[0] == '3'){
      finished = 1;
    }

    printf("\n");

  }

  printf("Good bye! \n\n");

  return EXIT_SUCCESS;
}

void showStudentInformation()
{
    printf("----------------------------------\n");
    printf("Name: %s\n", STUDENT_NAME);
    printf("Name: %s\n", STUDENT_ID);
    printf("Name: %s\n", STUDENT_EMAIL);
    printf("----------------------------------\n");
}
