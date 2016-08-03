
#ifndef HighScoreManager_hpp
#define HighScoreManager_hpp

#include <vector>
#include <string>

#include "HighScore.hpp"


/*
    Contains utility operations for interacting with the scores.txt file.
 
    Functionality includes: 
        Getting a list of high scores from the file.
        Sending a single record to the file. 
 
    Ability to print all high scores is derived from the getListFromFile() method
    and the logic to do so is currently present in the main.
*/
class HS_Manager {
    
public:
    static std::vector<HighScore> getListFromFile();
    static void sendToFile(std::vector<HighScore>);
    
};

#endif /* HighScoreManager_hpp */
