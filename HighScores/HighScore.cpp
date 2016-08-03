

#include "HighScore.hpp"

//constructor to use if a score has already been defined
HighScore::HighScore(Util::Score s) {
    score_record.username = s.username == "" ? Util::getUsername() : s.username;
    score_record.date = s.date == "" ? Util::getCurrentDate() : s.date;
    score_record.score = s.score == 0 ? Util::getScore() : s.score;
    
    user.username = score_record.username;
    user.highestScore = score_record.score;
}

//implementation for the default constructor
HighScore::HighScore() {
    score_record.username = Util::getUsername();
    score_record.date = Util::getCurrentDate();
    score_record.score = Util::getScore();
    
    user.username = score_record.username;
    user.highestScore = score_record.score;
}

//preparing the string to write
std::string HighScore::stringToWrite() {
    return std::to_string(score_record.score) + " - " + score_record.username + " -- " + score_record.date;
}

//returning the instance's user struct
Util::User HighScore::getUser() {
    return user;
}

//returning the score value as an int
int HighScore::getScore() {
    return score_record.score;
}