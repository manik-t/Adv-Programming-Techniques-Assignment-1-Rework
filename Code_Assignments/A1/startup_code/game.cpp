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
        std::cout << "load <g>" << std::endl;

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
            if(load_vec[0] == COMMAND_LOAD){
                loadBoard(stoi(load_vec[1]));
                boardLoaded = true;
            }

            else if(load_vec[0] == COMMAND_INIT && load_vec.size() == 4 && boardLoaded == true){
                // Checks if the input are actually digits
                if(Helper::isNumber(init_vec[1]) == false || Helper::isNumber(init_vec[2]) == false){
                    Helper::printInvalidInput();
                }

                else{
                    playerInitialised = initializePlayer(stoi(init_vec[1]), stoi(init_vec[2]), init_vec[3]);
                }
                
            }

            else if(userInput == COMMAND_QUIT){
                delete player;
                delete board;
                std::cout << userInput << std::endl;
            }

            else{
                Helper::printInvalidInput();
            }
        }

        if(playerInitialised == true){
            board->display(player);
            play();
            delete board;
        }

        else if(playerInitialised == false){
            std::cout << "Invalid position" << std::endl;
        }

        //std::cout << userInput << std::endl;

        load_vec.clear();
        
    }
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

    if(xPos > 9 ||xPos < 0 || yPos > 9 || yPos < 0){
        Helper::printInvalidInput();
    }
    

    else{

        if(dir == DIRECTION_NORTH){
            Position* position = new Position(yPos, xPos);
            Direction direction = NORTH;
            player->initialisePlayer(position, direction);
            playerInit = board->placePlayer(*position);
        }

        else if(dir == DIRECTION_EAST){
            Position* position = new Position(yPos, xPos);
            Direction direction = EAST;
            player->initialisePlayer(position, direction);
            playerInit = board->placePlayer(*position);
        }

        else if(dir == DIRECTION_SOUTH){
            Position* position = new Position(yPos, xPos);
            Direction direction = SOUTH;
            player->initialisePlayer(position, direction);
            playerInit = board->placePlayer(*position);
        }

        else if(dir == DIRECTION_WEST){
            Position* position = new Position(yPos, xPos);
            Direction direction = WEST;
            player->initialisePlayer(position, direction);
            playerInit = board->placePlayer(*position);
        }

        else{
            Helper::printInvalidInput();
        }
    }
    
    return playerInit; // feel free to revise this line.
}

void Game::play()
{
    //TODO
}

void Game::printGameMenu(){
    // Print the game menu
    std::cout << "You can use the following commands to play the game:" << std::endl;
    std::cout << "load <g>" << std::endl;
    std::cout << "      g: number of the game board to load" << std::endl;
    std::cout << std::endl;
    std::cout << "init <x>, <y>, <direction>" << std::endl;
    std::cout << "      x: horizontal positoin of the car on the board (between 0 & 9)" << std::endl;
    std::cout << "      y: vertical positoin of the car on the board (between 0 & 9)" << std::endl;
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