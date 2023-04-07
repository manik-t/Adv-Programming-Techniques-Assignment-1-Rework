#include "game.h"
#include "helper.h"

#define STARTGAME       "1"
#define SHOWSTUDENTINFO "2"
#define QUIT            "3"

using std::string;
using std::vector;

void showStudentInformation(string name, string id, string email);

void printMenu();

// int removeSpace(string userInput);

int main()
{
    /**
     * The approach I took for this project was to incrementally add functionality to it and test it.
     * First I would try to figure out the logic and what functions I will need to use. After I had an idea
     * of what had to be done I would implement the functionality of the current increment, review and ensure 
     * there were no errors with the newly implementd functions. Then I would pick another set of functions
     * to implement in the next increment. Repeat until the program is finished.
     * 
     * I initially had issues with how pointers worked and issues with passing values from funtion to funtion.
     * Eventually with more practice and a better understanding of the theory behind c++ these issues were no longer
     * occuring. Other issues regarded input validation however that was resolved through extensive testing of the 
     * program and recording how it would react to certain inputs.
     * 
     * The start up code could have been more modular. Through the assignment I would find that if I just followed
     * the structure of the start up code my program will be monolithic. Adding new functions to break up these
     * large functions allowed for a more modular program and made troubleshooting easier.
     */
    printMenu();

    // Initialise userInput so program does not crash if user hits enter right after starting program.
    string userInput;
    vector<string> inputVec;

    while(userInput != QUIT){
        userInput = Helper::readInput();
        Helper::splitString(userInput, inputVec, " ");
        
        if(inputVec.size() > 1 || inputVec.size() == 0){
            inputVec[0] = "invalid";
        }
        
        bool isNum = Helper::isNumber(inputVec[0]);

        if(isNum == true){
            if(inputVec[0] == STARTGAME){
                Game* game = new Game();
                game->start();
                delete game;
            }

            else if(inputVec[0] == SHOWSTUDENTINFO){
                showStudentInformation("Manik Thapliyal", "s3953664", "s3953664@student.rmit.edu.au");
            }

            else{
                Helper::printInvalidInput();
            }
        }

        else{
            Helper::printInvalidInput();
        }

        printMenu();
    }

    std::cout << "Good bye!\n\n";

    return EXIT_SUCCESS;
}

void printMenu(){
    std::cout << std::endl;
    // Prints menu options and prompts for input
    std::cout << "Welcome to Car Board" << std::endl;
    std::cout << "--------------------" << std::endl;
    std::cout << "1. Play game" << std::endl;
    std::cout << "2. Show student information" << std::endl;
    std::cout << "3. Quit" << std::endl;
    std::cout << std::endl;
    std::cout << "Please enter your choice:" << std::endl;
}

void showStudentInformation(string name, string id, string email){
    // Prints the student information passed to the function
    std::cout << "----------------------------------" << std::endl;
    std::cout << "Name:" << name << std::endl;
    std::cout << "NO:" << id << std::endl;
    std::cout << "Email:" << email << std::endl;
    std::cout << "----------------------------------" << std::endl;
    std::cout << std::endl;
}