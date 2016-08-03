
#include "UsersManager.hpp"
#include "Util.hpp"

#include <fstream>

//Boolean value returned if a user exists. 
bool USR_Manager::checkIfUserExists(Util::User user) {
    return findUserByUsername(user.username).username.compare(user.username) == 0;
}

//sends a single user record to the file appending to the existing contents
void USR_Manager::sendToFile(Util::User user) {
    
    std::ofstream output;
    output.open(Util::usersFilePath(), std::ofstream::out | std::ofstream::app);
    
    //check if saved user.highestscore is greater than the current highestscore score.
    if (checkIfUserExists(user))
    {
        int highscore_from_file = findUserByUsername(user.username).highestScore;
        
        if (user.highestScore > highscore_from_file)
            output << user.username + " - " + std::to_string(user.highestScore) + "\n";
    }
    else
    {
        output << user.username + " - " + std::to_string(user.highestScore) + "\n";
    }
    
    output.close();
}

//Returns a single Util:User if the user exists in the file.
Util::User USR_Manager::findUserByUsername(std::string username) {
    std::ifstream read;
    std::string line;
    Util::User user_found;
    
    read.open(Util::usersFilePath());
    while (getline(read, line)) {
        if (line.substr(0, line.find(" - ")) == username) {
            user_found.username = line.substr(0, line.find(" - "));
            user_found.highestScore = std::stoi(line.substr(line.find(" - ") + 3));
            break;
        }
    }
    return user_found;
}

//Gets a vector<Util::User> of all entries in the file.
std::vector<Util::User> USR_Manager::getUsersFromFile() {
    std::ifstream read(Util::usersFilePath());
    std::string line;
    std::vector<Util::User> userlist;
    
    while (getline(read, line)) {
        Util::User u;
        u.username = line.substr(0, line.find(" - "));
        u.highestScore = std::stoi(line.substr(line.find(" - ") + 3));
        userlist.push_back(u);
    }
    
    return userlist;
}

/*
 Takes fetches current list of users and updates the appropriate user with
 their new highscore. Then saves the updated list to the users.txt file.
*/
void USR_Manager::updateUserHighScore(Util::User user) {
    std::vector<Util::User> userlist = getUsersFromFile();
    std::ofstream output;
    
    for (int i = 0; i < userlist.size(); i++)
        if (userlist[i].username == user.username &&
            userlist[i].highestScore < user.highestScore)
            userlist[i].highestScore = user.highestScore;
    
    output.open(Util::usersFilePath(), std::ofstream::out | std::ofstream::trunc);
    for (auto &u : userlist)
        output << u.username + " - " + std::to_string(u.highestScore) + "\n";
    output.close();
    
}

void USR_Manager::deleteUser(Util::User user) {
    std::vector<Util::User> userlist = getUsersFromFile();
    std::ofstream output;
    
    for (int i = 0; i < userlist.size(); i++)
        if (userlist[i].username == user.username)
            userlist.erase(userlist.begin() + i);
    
    output.open(Util::usersFilePath(), std::ofstream::out | std::ofstream::trunc);
    for (auto &u : userlist)
        output << u.username + " - " + std::to_string(u.highestScore) + "\n";
    output.close();

}

//Returns a (int) count of the number of records in a file.
int USR_Manager::lineCount() {
    std::ifstream read(Util::usersFilePath());
    std::string line;
    int count = 0;
    
    while (getline(read, line))
        ++count;
    
    return count;
}