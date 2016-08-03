
#ifndef HighScore_hpp
#define HighScore_hpp

#include <stdio.h>
#include "Util.hpp"

/*
 Class which will contain the information to write to the high scores file.
 
 functionality includes:
    storing data to be written to the high scores file
    preparing a string to write to the file
    getting the score as an int value
*/

class HighScore {
    
public:
    HighScore();
    HighScore(Util::Score score_in);
    
    std::string stringToWrite();
    void addUser(Util::User u);
    void addScore(Util::Score s);
    Util::User getUser();
    int getScore();

private:
    Util::User user;
    Util::Score score_record;
};

#endif /* HighScore_hpp */
