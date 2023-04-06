#include "game.h"
using std::string;
using std::vector;

Game::Game()
{
    this->board = new Board();
    this->player = new Player();
}

Game::~Game()
{
    delete board;
    delete player;
}


void Game::start()
{   
    string userInput;
    bool boardLoaded = false;
    bool playerInitialised = false;
    //bool validInit = false;
    vector<string> load_vec;
    vector<string> init_vec;
    //vector<string>* ptrLoad_vec = &load_vec;


    printGameMenu();

    while(userInput != COMMAND_QUIT){
        // Print valid inputs
        std::cout << "----------------------------------------------------------" << std::endl;
        std::cout << "At this stage of the game, only these inputs are acceptable:" << std::endl;
        std::cout << "generate <d>, <p>" << std::endl;

        if(boardLoaded == true){
            std::cout << "init <x>, <y>, <direction>" << std::endl;
        }

        std::cout << "quit" << std::endl;
        std::cout << std::endl;
        std::cout<< "Please enter your choice:" <<std::endl;

        // Read user input
        userInput = Helper::readInput();

        Helper::splitString(userInput, load_vec, " ");
        Helper::splitString(userInput, init_vec, ", ");

        if(load_vec.size() == 0){
            userInput = "invalid";
            Helper::printInvalidInput();
        }
        
        

        else{
            if(load_vec.size() == 3 && load_vec[0] == COMMAND_GENERATE_RANDOM){
                int size;
                float probability;

                if(Helper::isNumber(init_vec[1]) == true && Helper::isNumber(init_vec[2])){
                    size = stoi(init_vec[1]);
                    probability = stof(init_vec[2]);
                }

                else{
                    size = -1;
                    probability = -1;
                }

                std::cout << probability << " " << size << std::endl;


                if(probability > 1 || probability < 0 || size < 10 || size > 20){
                    Helper::printInvalidInput();
                }

                else{
                    boardLoaded = true;
                    board->generate(size, probability);
                }  
            }

            else if(load_vec[0] == COMMAND_INIT && load_vec.size() == 4 && boardLoaded == true){
                // Checks if the input are actually digits
                if(Helper::isNumber(init_vec[1]) == false || Helper::isNumber(init_vec[2]) == false){
                    Helper::printInvalidInput();
                }

                else{
                    playerInitialised = initializePlayer(stoi(init_vec[1]), stoi(init_vec[2]), init_vec[3]);

                    if(playerInitialised == false){
                        Helper::printInvalidInput();
                    }
                }
                
            }

            else if(load_vec[0] == COMMAND_QUIT){
                userInput = COMMAND_QUIT;
            }

            else{
                Helper::printInvalidInput();
            }
        }

        if(playerInitialised == true){
            board->display(player);
            play();
            userInput = COMMAND_QUIT;
        }

        load_vec.clear();
        
    }

    std::cout << "Leaving game" << std::endl;
    std::cout << std::endl;
}

bool Game::loadBoard(int boardId)
{
    bool boardLoaded = false;

    if(boardId == 1 || boardId == 2){
        boardLoaded = true;
        board->load(boardId);
    }

    return boardLoaded; // feel free to revise this line, depending on your implementation.
}

bool Game::initializePlayer(int xPos, int yPos, std::string dir)
{
    bool playerInit = false;

    // Initialise player and place it on the board
    if(dir == DIRECTION_NORTH){
        Position* position = new Position(xPos, yPos);
        Direction direction = NORTH;
        player->initialisePlayer(position, direction);
        playerInit = board->placePlayer(*position);
    }
    else if(dir == DIRECTION_EAST){
        Position* position = new Position(xPos, yPos);
        Direction direction = EAST;
        player->initialisePlayer(position, direction);
        playerInit = board->placePlayer(*position);
    }
    else if(dir == DIRECTION_SOUTH){
        Position* position = new Position(xPos, yPos);
        Direction direction = SOUTH;
        player->initialisePlayer(position, direction);
        playerInit = board->placePlayer(*position);
    }
    else if(dir == DIRECTION_WEST){
        Position* position = new Position(xPos, yPos);
        Direction direction = WEST;
        player->initialisePlayer(position, direction);
        playerInit = board->placePlayer(*position);
    }
    // The direction was invalid
    else{
        playerInit = false;
    }

    return playerInit; // feel free to revise this line.
}

void Game::play()
{
    string userInput = "empty";
    //bool validMove = false;
    PlayerMove validPos;
    vector<string> inputVec;
    int totalPlayerMoves = 0;

    while(userInput != COMMAND_QUIT){
        // Print valid inputs
        std::cout << "----------------------------------------------------------" << std::endl;
        std::cout << "At this stage of the game, only these inputs are acceptable:" << std::endl;
        std::cout << "forward" << std::endl;
        std::cout << "turn_left (or l)" << std::endl;
        std::cout << "turn_right (or r)" << std::endl;
        std::cout << "quit" << std::endl;
        userInput = Helper::readInput();
        
        Helper::splitString(userInput, inputVec, " ");

        // If the player is input a string with more than one word then it counts as invalid

        if(inputVec.size() > 1){
            inputVec[0] = "invalid";
        }


        if(inputVec[0] == COMMAND_FORWARD || inputVec[0] == COMMAND_FORWARD_SHORTCUT){
            // Saves the original position of the player
            Position ogPos = player->position;
            Position newPos = Position();
            
            newPos = player->getNextForwardPosition();
            player->updatePosition(newPos);
            validPos = board->movePlayerForward(player);
            
            // If the cell is blocked then the position is reverted back to original position

            if(validPos == PLAYER_MOVED){
                board->display(player);
                totalPlayerMoves += 1;
            }

            else if(validPos == CELL_BLOCKED){
                std::cout << "Cell is blocked" << std::endl;
                player->updatePosition(ogPos);
            }

            // If new position is outside bounds then revert back to original position
            else{
                std::cout << "The car is at the edge of the board and cannot move further in that direction" << std::endl;
                player->updatePosition(ogPos);
            }

            std::cout << std::endl;
        }

        else if(inputVec[0] == COMMAND_TURN_LEFT || inputVec[0] == COMMAND_TURN_LEFT_SHORTCUT){
            TurnDirection turnTo = TURN_LEFT;
            std::cout << "Turning left" << std::endl;
            player->turnDirection(turnTo);
            board->display(player);
        }

        else if(inputVec[0] == COMMAND_TURN_RIGHT || inputVec[0] == COMMAND_TURN_RIGHT_SHORTCUT){
            TurnDirection turnTo = TURN_RIGHT;
            std::cout << "Turning right" << std::endl;
            player->turnDirection(turnTo);
            board->display(player);
        }

        else if(inputVec[0] == COMMAND_QUIT){
            userInput = COMMAND_QUIT;
        }

        else{
            Helper::printInvalidInput();
        }

        // Resets the input so program won't do anything if user just hits enter over and over
        inputVec[0] = "clear";
    }

    std::cout << "Total player moves: " << totalPlayerMoves << std::endl;
    std::cout << std::endl;
}

void Game::printGameMenu(){
    // Print the game menu
    std::cout << "You can use the following commands to play the game:" << std::endl;
    std::cout << "generate <d>, <p>" << std::endl;
    std::cout << "      d: the dimension of the game board to be generated" << std::endl;
    std::cout << "      p: the probability of the blocks on board to be generated randomly" << std::endl;
    std::cout << std::endl;
    std::cout << "init <x>, <y>, <direction>" << std::endl;
    std::cout << "      x: horizontal position of the car on the board (between 0 & 9)" << std::endl;
    std::cout << "      y: vertical position of the car on the board (between 0 & 9)" << std::endl;
    std::cout << "      x: direction of the car's movement (north, east, south, west)" << std::endl;
    std::cout << std::endl;
    std::cout << "forward (or f)" << std::endl;
    std::cout << "turn left (or l)" << std::endl;
    std::cout << "turn right <or r>" << std::endl;
    std::cout << "quit" << std::endl;
    std::cout << "Press enter to continue..." << std::endl;
    std::cout << "-------------------------------------------------------------------" <<std::endl;

    Helper::readInput();

    // Print the template board
    std::cout << std::endl;
    std::cout << "| |";

    for(int i=0; i < 10; i++){
        std::cout << i << "|";
    }

    std::cout << std::endl;

    for(int i=0; i < 10; i++){
        std::cout << "|" << i << "|";
        for(int j = 0; j < 10; j++){
            std::cout << " |";
        }

        std::cout << std::endl;
    }
}