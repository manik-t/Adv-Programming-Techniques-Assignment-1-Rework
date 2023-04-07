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
    // Initialise a board
    load(1);
}

Board::~Board()
{
    delete board;
}

void Board::load(int boardId)
{   
    
    // Set pointer to a copy of the predefined boards
    if(boardId == 1){
        this->board = new vector<vector<Cell>> (BOARD_1);
    }

    else if(boardId == 2){
        this->board = new vector<vector<Cell>> (BOARD_2);
    }
}

void Board::generate(int size, float probability){
    // Create a new vector of vectors
    vector<vector<Cell>> fullBoard;
    probability = probability * 100;
    int block;

    for(int i = 0; i < size; i++){
        // Create a temp vector
        vector<Cell> temp;

        for(int j = 0; j < size; j++){
            block = rand() % 100;

            // Randomly place blocks dependent on the probability
            if(probability > block){
                temp.push_back(BLOCKED);
            }

            else{
                temp.push_back(EMPTY);
            }
        }

        // Insert temp vector into the vector of vectors
        fullBoard.push_back(temp);
    }

    // Set pointer to a copy of fullBoard in the heap
    this->board = new vector<vector<Cell>> (fullBoard);
}



bool Board::placePlayer(Position position)
{
    bool validPos = false;
    long boardSize = (*board).size();

    // Check if position is within bounds
    if(position.x > boardSize-1 || position.x < 0 || position.y > boardSize-1 || position.y < 0){
        validPos = false;
    }

    else if((*board)[position.y][position.x] != BLOCKED){
        // Place player on board and return true
        validPos = true;
        (*board)[position.y][position.x] = PLAYER;
    }
    
    return validPos;
}

PlayerMove Board::movePlayerForward(Player* player)
{
    Position pos = player->position;
    PlayerMove move = CELL_BLOCKED;
    long boardSize = (*board).size();

    // Check if new position is within bounds
    if(pos.x > boardSize-1 || pos.x < 0 || pos.y > boardSize-1 || pos.y < 0){
        move = OUTSIDE_BOUNDS;
    }

    // Check if position is blocked
    else if((*board)[pos.y][pos.x] == BLOCKED){
        move = CELL_BLOCKED;
    }

    // Remove player from board then place it new position, retrun true
    else if((*board)[pos.y][pos.x] == EMPTY){
        move = PLAYER_MOVED;
        
        for(int i = 0; i < boardSize; i++){
            for(int j = 0; j < boardSize; j++){
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
    long boardSize = (*board).size();
    int rowNum = 0;
    int colNum = 0;

    // Print columns
    std::cout << std::endl;
    std::cout << "| |";

    for(int i=0; i < boardSize; i++){
        std::cout << colNum << "|";
        colNum += 1;
        if(colNum == DEFAULT_BOARD_DIMENSION){
            colNum = 0;
        }
    }

    std::cout << std::endl;

    // Print each row
    for(int i = 0; i < boardSize; i++){
        std::cout << LINE_OUTPUT << rowNum << LINE_OUTPUT;
        rowNum += 1;

        if(rowNum == DEFAULT_BOARD_DIMENSION){
            rowNum = 0;
        }

        for(int j = 0; j < boardSize; j++){
            // Display if selected cell is blocked, player or empty
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