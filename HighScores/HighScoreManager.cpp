
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

#include "Util.hpp"
#include "HighScoreManager.hpp"


//Sends the entire sorted list of scores to the file.
void HS_Manager::sendToFile(std::vector<HighScore> scores) {
    
    //sort list
    std::sort(scores.begin(), scores.end(), [](HighScore& score1, HighScore& score2)
    {
        return score1.getScore() > score2.getScore();
    });
    
    if (scores.size() > 10)
        while (scores.size() > 10)
            scores.pop_back();
    
    std::ofstream output;
    output.open(Util::highscoresFilePath(), std::ofstream::out | std::ofstream::trunc);
    for(auto &score : scores)
        output << score.stringToWrite() + "\n";
    output.close();
}

//Gets the entire list from the file.
std::vector<HighScore> HS_Manager::getListFromFile() {
    std::ifstream input;
    std::string line;
    std::vector<HighScore> scoresList;
    
    input.open(Util::highscoresFilePath());
    while (getline(input, line)) {
        Util::Score s;
        std::string u_d_inline = line.substr(line.find(" - ") + 3);
        
        s.score = std::stoi(line.substr(0, line.find(" - ")));
        s.username = u_d_inline.substr(0, u_d_inline.find(" -- "));
        s.date = u_d_inline.substr(u_d_inline.find(" -- ") + 4);
        
        scoresList.push_back(HighScore::HighScore(s));
    }
    
    return scoresList;
}
