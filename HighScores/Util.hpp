
#ifndef Util_hpp
#define Util_hpp

#include <stdio.h>
#include <string>


/*
 Contains utility operations for the main file.
 */
namespace Util {
    struct Score {
        std::string username = "";
        std::string date = "";
        int score = 0;
    };
    
    struct User {
        std::string username = "";
        int highestScore = 0;
    };
    
    //output methods
    void printMenu();
    void printCurrentHighScore();
    
    //input methods
    void saveToFile(std::string in);
    std::string getCurrentDate();
    std::string getUsername();
    std::string getName();
    int getScore();
    int menuSelection();
    
    //file operations
    std::string highscoresFilePath();
    std::string usersFilePath();

}

#endif /* Util_hpp */
