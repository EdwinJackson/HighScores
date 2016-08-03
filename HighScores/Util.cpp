
#include "Util.hpp"
#include <iostream>
#include <ctime>
#include <cctype>

namespace Util {
    
    /**
     
     
     INPUT METHODS
     
     
     */
    
    //returns the current date as a string
    std::string getCurrentDate() {
        time_t t = time(0);   // get time now
        struct tm * now = localtime( & t );
        return std::to_string(now->tm_mday) + "/" + std::to_string(now->tm_mon + 1) + "/" + std::to_string(now->tm_year + 1900);
    }
    
    //prompts the user for input, validates input, and returns a string.
    std::string getUsername() {
        std::string username;
        bool isValid = true;
        do {
            std::cout << "Please enter your username! Usernames can only be letters, No spaces, or numbers!" << std::endl;
            std::cin >> username;
            for (auto& c : username) {
                isValid = std::isalpha(c);
                if (!isValid)
                    break;
            }
        } while (!isValid);
        return username;
    }
    
    //prompts the user for an integer, validates, and returns an int
    int getScore() {
        int score = 10;
        do {
            std::cout << "scores can only be integers" << std::endl;
            std::cin >> score;
//            score = score != 0 ? score : 0;
        } while (false);
        return score;
    }
    
    //static location of the highscores.txt file
    std::string highscoresFilePath() {
        return "/Users/edwinjackson/Documents/cpp/HighScores/HighScores/HighScores/highscores.txt";
    }
    
    //static location of the users.txt file
    std::string usersFilePath() {
        return "/Users/edwinjackson/Documents/cpp/HighScores/HighScores/HighScores/users.txt";
    }
    
    /**
     
     
     OUTPUT METHODS
     
     
     */
    
    //prints the main menu
    void printMenu() {
        std::cout
        << "1 - Set new score" << std::endl
        << "2 - print current score" << std::endl
        << "3 - print all high scores" << std::endl
        << "4 - Change user" << std::endl
        << "5 - Delete current user" << std::endl
        << "6 - Quit" << std::endl;
    }
    
    //validates user input for selection at the main menu
    int menuSelection() {
        int sel = 6;
        do {
            if (!(sel > 0 && sel < 7)) {
                std::cout << "must be a number between 1 and 5";
                std::cin.get();
            }
            std::cin >> sel;
        } while (!(sel > 0 && sel < 7));
        
        return sel;
    }
    
}