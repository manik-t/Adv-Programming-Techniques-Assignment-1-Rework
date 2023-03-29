#include "player.h"

Position::Position()
{
    
}


Position::Position(int x, int y)
{
    this->x = x;
    this->y = y;
}

Player::Player()
{
    //TODO
}

void Player::initialisePlayer(Position* position, Direction direction)
{
    this->position = *position;
    //std::cout << position->x << position->y << std::endl;
    this->direction = direction;
}

void Player::turnDirection(TurnDirection turnDirection)
{
    //TODO
}

Position Player::getNextForwardPosition()
{
    //TODO

    return this->position;
}

void Player::updatePosition(Position position)
{
    //TODO
}

void Player::displayDirection()
{
    if(direction == NORTH){
        printf(DIRECTION_ARROW_OUTPUT_NORTH);
    }

    else if(direction == EAST){
        printf(DIRECTION_ARROW_OUTPUT_EAST);
    }
    
    else if(direction == SOUTH){
        printf(DIRECTION_ARROW_OUTPUT_SOUTH);
    }

    
    else if(direction == WEST){
        printf(DIRECTION_ARROW_OUTPUT_WEST);
    }
}
