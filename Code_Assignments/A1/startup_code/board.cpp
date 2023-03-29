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
        for(int i = 0; i < 10; i++){
            vector<Cell> temp;

            for(int j = 0; j < 10; j++){
                temp.push_back(BOARD_1[i][j]);
            }
            
            final_vec.push_back(temp);
        }

        board = &final_vec;
    }

    else if(boardId == 2){
        this->board = new vector<vector<Cell>> (BOARD_2);
        for(int i = 0; i < 10; i++){
            vector<Cell> temp;

            for(int j = 0; j < 10; j++){
                temp.push_back(BOARD_2[i][j]);
            }
            
            final_vec.push_back(temp);
        }

        board = &final_vec;
    }


    // Print out the selected board
    //std::cout << std::endl;
    //std::cout << "| |";
//
    //for(int i=0; i < 10; i++){
    //    std::cout << i << "|";
    //}
//
    //std::cout << std::endl;
//
    //for(int i = 0; i < 10; i++){
    //    std::cout << LINE_OUTPUT << i << LINE_OUTPUT;
//
    //    for(int j = 0; j < 10; j++){
    //        Cell selected = (*board)[i][j];
//
    //        if(selected == BLOCKED){
    //            std::cout << BLOCKED_OUTPUT << LINE_OUTPUT;
    //        }
//
    //        else{
    //            std::cout << EMPTY_OUTPUT << LINE_OUTPUT;
    //        }
    //    }
//
    //    std::cout << std::endl;
    //}

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
    //std::cout << position.x << std::endl;
    //std::cout << position.y << std::endl;
    bool validPos = false;

    if((*board)[position.x][position.y] != BLOCKED){
        validPos = true;
        (*board)[position.x][position.y] = PLAYER;
    }
    
    return validPos; // feel free to revise this line, depending on your implementation.
}

PlayerMove Board::movePlayerForward(Player* player)
{
    // TODO
    return PLAYER_MOVED;
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
            Cell selected = final_vec[i][j];

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


