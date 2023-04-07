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
     * First I would check the functionality required for each requirement and write the logic of how
     * to meet the requirement. Then I would implement the functions testing them as I complete the current
     * increment. After I have finished the implementation I would review and revies the code until I was 
     * sure that the code will react as expected. Then I would repeat the same process for all the other
     * requirements until all requirements had been met, slowly adding more functionality with each new
     * increment.
     * 
     * I intially had issues with pointers as well as passing data from function to function. Eventually as I
     * got a better understanding of the theory behind c++ and more experience with the programming language
     * these issues would no longer occur. I also would have issues with the input validation however this was
     * remedied by extensively testing the program as well as reviewing the code to ensure the error wasn't due
     * to an error in the programs logic.
     * 
     * The start up code could have had more functions from the start to help it be more modular. As I was coding
     * the program was becoming more and more monolithic and had a sever impact on testing the code and the 
     * readability of it. However, this was an easy issue to fix by just adding new functions as I coded. By making
     * it modular it had improved the readability of the code and made it easier to see where errors were occuring.
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