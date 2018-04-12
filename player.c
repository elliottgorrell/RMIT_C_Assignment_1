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
    /* TODO */
}

Position getNextForwardPosition(const Player * player)
{
    /* TODO */
    Position position;

    return position;
}

void updatePosition(Player * player, Position position)
{
    /* TODO */
}

void displayDirection(Direction direction)
{
  if (direction == NORTH) printf(DIRECTION_ARROW_OUTPUT_NORTH);
  else if (direction == SOUTH) printf(DIRECTION_ARROW_OUTPUT_SOUTH);
  else if (direction == EAST) printf(DIRECTION_ARROW_OUTPUT_EAST);
  else if (direction == WEST) printf(DIRECTION_ARROW_OUTPUT_WEST);
}
