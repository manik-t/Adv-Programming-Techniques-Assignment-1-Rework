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
     * TODO: here's the main function. You can write the "main menu" loop/code
     * here or you can make separate functions - up to you.
     */
    printMenu();

    // Initialise userInput so program does not crash if user hits enter right after starting program.
    string userInput = "invalid";
    vector<string> inputVec;

    while(userInput != "3"){
        userInput = Helper::readInput();
        Helper::splitString(userInput, inputVec, " ");
        
        if(inputVec.size() > 1){
            inputVec[0] = "invalid";
        }
        
        bool isNum = Helper::isNumber(inputVec[0]);

        if(isNum == true){
            if(inputVec[0] == STARTGAME){
                Game* game = new Game();
                game->start();
                //delete game;
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