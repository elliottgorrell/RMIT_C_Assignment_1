/******************************************************************************
** Student name: 	Elliott Gorrell
** Student number: 	s3452258
** Course: 			Advanced Programming Techniques - S1 2018
******************************************************************************/

#include "player.h"

void initialisePlayer(Player * player, Position * position, Direction direction)
{
    player->position = *position;
    player->direction = direction;
    player->moves = 0;
}

void turnDirection(Player * player, TurnDirection turnDirection)
{
    switch(turnDirection){
      case TURN_LEFT :
        if ((int) player->direction == 0) {
          player->direction = 3;
        }
        else {
          player->direction -= 1;
        }
        break;

      case TURN_RIGHT :
        if ((int) player->direction == 3) {
          player->direction = 0;
        }
        else {
          player->direction += 1;
        }
        break;
    }
}

Position getNextForwardPosition(const Player * player)
{
    Position position;
    int yIncrementer = 0;
    int xIncrementer = 0;

    switch(player->direction){
      case NORTH :
        yIncrementer = 1;
        break;
      case SOUTH :
        yIncrementer = -1;
        break;
      case EAST :
        xIncrementer = 1;
        break;
      case WEST :
        xIncrementer = -1;
        break;
    }

    position.x = (xIncrementer > 0) ? player->position.x + xIncrementer : player->position.x - xIncrementer;
    position.y = (yIncrementer > 0) ? player->position.y + yIncrementer : player->position.y - yIncrementer;


    return position;
}

void updatePosition(Player * player, Position position)
{
    player->position = position;
}

void displayDirection(Direction direction)
{
  if (direction == NORTH) printf(DIRECTION_ARROW_OUTPUT_NORTH);
  else if (direction == SOUTH) printf(DIRECTION_ARROW_OUTPUT_SOUTH);
  else if (direction == EAST) printf(DIRECTION_ARROW_OUTPUT_EAST);
  else if (direction == WEST) printf(DIRECTION_ARROW_OUTPUT_WEST);
}
