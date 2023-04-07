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
    this->direction = direction;
}

void Player::turnDirection(TurnDirection turnDirection)
{
    if(turnDirection == TURN_LEFT){

        if(direction == NORTH){
            direction = WEST;
        }

        else if(direction == EAST){
            direction = NORTH;
        }

        else if(direction == SOUTH){
            direction = EAST;
        }

        else if(direction == WEST){
            direction = SOUTH;
        }
    }

    else if(turnDirection == TURN_RIGHT){
        if(direction == NORTH){
            direction = EAST;
        }

        else if(direction == EAST){
            direction = SOUTH;
        }

        else if(direction == SOUTH){
            direction = WEST;
        }

        else if(direction == WEST){
            direction = NORTH;
        }
    }
}

Position Player::getNextForwardPosition()
{
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
