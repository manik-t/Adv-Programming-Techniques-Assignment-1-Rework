 #include "board.h"

using std::vector;

const vector<vector<Cell>> Board::BOARD_1 =
{
    { BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY },
    { EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, BLOCKED, EMPTY, BLOCKED, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED }
};

const vector<vector<Cell>> Board::BOARD_2 =
{
    { BLOCKED, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY }
};

Board::Board()
{
    
}

Board::~Board()
{
    delete board;
}

void Board::load(int boardId)
{   
    
    // Fill vector of vectors with pre-defined boards
    // Assign board pointer to final_vec
    if(boardId == 1){
        this->board = new vector<vector<Cell>> (BOARD_1);
    }

    else if(boardId == 2){
        this->board = new vector<vector<Cell>> (BOARD_2);
    }

    std::cout << std::endl;
    std::cout << "| |";

    for(int i=0; i < 10; i++){
        std::cout << i << "|";
    }

    std::cout << std::endl;

    for(int i = 0; i < 10; i++){
        std::cout << LINE_OUTPUT << i << LINE_OUTPUT;

        for(int j = 0; j < 10; j++){
            Cell selected = (*board)[i][j];

            if(selected == BLOCKED){
                std::cout << BLOCKED_OUTPUT << LINE_OUTPUT;
            }

            else{
                std::cout << EMPTY_OUTPUT << LINE_OUTPUT;
            }
        }

        std::cout << std::endl;
    }
}

bool Board::placePlayer(Position position)
{
    bool validPos = false;

    if((*board)[position.y][position.x] != BLOCKED){
        validPos = true;
        (*board)[position.y][position.x] = PLAYER;
    }
    
    return validPos; // feel free to revise this line, depending on your implementation.
}

PlayerMove Board::movePlayerForward(Player* player)
{
    Position pos = player->position;
    PlayerMove move = CELL_BLOCKED;

    if(pos.x > 9 || pos.x < 0 || pos.y > 9 || pos.y < 0){
        move = OUTSIDE_BOUNDS;
    }

    else if((*board)[pos.y][pos.x] == BLOCKED){
        move = CELL_BLOCKED;
    }

    else if((*board)[pos.y][pos.x] == EMPTY){
        move = PLAYER_MOVED;
        
        for(int i = 0; i < 10; i++){
            for(int j = 0; j < 10; j++){
                if((*board)[i][j] == PLAYER){
                    (*board)[i][j] = EMPTY;
                }
            }
        }

        placePlayer(pos);
    }
    return move;
}

void Board::display(Player* player)
{
    std::cout << std::endl;
    std::cout << "| |";

    for(int i=0; i < 10; i++){
        std::cout << i << "|";
    }

    std::cout << std::endl;

    for(int i = 0; i < 10; i++){
        std::cout << LINE_OUTPUT << i << LINE_OUTPUT;

        for(int j = 0; j < 10; j++){
            Cell selected = (*board)[i][j];

            if(selected == BLOCKED){
                std::cout << BLOCKED_OUTPUT << LINE_OUTPUT;
            }

            else if(selected == PLAYER){
                player->displayDirection();
                std::cout << LINE_OUTPUT;
            }

            else{
                std::cout << EMPTY_OUTPUT << LINE_OUTPUT;
            }
        }

        std::cout << std::endl;
    }
}


