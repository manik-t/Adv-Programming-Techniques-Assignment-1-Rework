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
    Position temp = Position();
    if(direction == NORTH){
        temp.x = position.x;
        temp.y = (position.y - 1);
    }

    else if(direction == SOUTH){
        temp.x = position.x;
        temp.y = (position.y + 1);
    }

    else if(direction == EAST){
        temp.y = position.y;
        temp.x = (position.x + 1);
    }

    else if(direction == WEST){
        temp.y = position.y;
        temp.x = (position.x - 1);
    }

    std::cout << temp.x << " " << temp.y << std::endl;

    return temp;
}

void Player::updatePosition(Position position)
{
    this->position.x = position.x;
    this->position.y = position.y;
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
