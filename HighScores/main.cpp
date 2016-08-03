/*
 High Scores manager
 
 Edwin Jackson & Harlan Batchelor
 
 Due to security permission issues on Ed's window's machine we were unable to use a .dat file
 to complete the assignment. The program would simply stop with read-access permission errors,
 so we used a .txt file instead. 
 
 The main contains the control logic for how the program is executed.
 Possibilties are separated in a switch statemet.
 
*/
#include <iostream>
#include <ctime>

#include "time.h"
#include "Util.hpp"
#include "HighScoreManager.hpp"
#include "UsersManager.hpp"

using namespace std;

int main() {
    
    Util::User user;
    Util::Score score;
    vector<HighScore> scores = HS_Manager::getListFromFile();
    bool play = true;
    string goback = "";
    
    cout << "New users will be saved, existing users can update their status" << endl;
    cout << "Please enter your username..." << endl;
    
    cin >> user.username;
    
    string response = USR_Manager::checkIfUserExists(user)
        ? "Welcome back " + user.username
        : "Welcome " + user.username + "! please set a new high score for your self!";
    
    cout << response << endl;
    
    if (USR_Manager::checkIfUserExists(user))
        user = USR_Manager::findUserByUsername(user.username);
    
    while (play) {
        
        cout << endl << endl;
        
        Util::printMenu();
        int selection = Util::menuSelection();
        
        switch (selection) {
            case 1: // set a new highscore
                cout << "Setting a new Highscore, please enter the new high score for yourself." << endl;
                score.score = Util::getScore();
                score.date = Util::getCurrentDate();
                score.username = user.username;
                user.highestScore = score.score;
                
                scores.push_back(HighScore::HighScore(score));
                HS_Manager::sendToFile(scores);
                
                if (USR_Manager::checkIfUserExists(user))
                    USR_Manager::updateUserHighScore(user);
                else
                    USR_Manager::sendToFile(user);
                
                break;
                
            case 2: // print the current user highscore
                cout
                << "Current Highest score for " << user.username << ": "
                << USR_Manager::findUserByUsername(user.username).highestScore << endl;
                break;
            case 3: // print all highscores
                cout << "Top 10 highscores!" << endl
                << " --------------------------------" << endl;
                for (auto &rec : HS_Manager::getListFromFile())
                    cout << rec.stringToWrite() << endl;
                break;

            case 4: // change user
                
                cout << "Please enter the username" << endl;
                cin >> user.username;
                
                if (USR_Manager::checkIfUserExists(user))
                    user = USR_Manager::findUserByUsername(user.username);
                
                cout << "Now using: " << user.username << endl;
                
                break;
            case 5: // delete current user
                USR_Manager::deleteUser(user);
                cout << "User " << user.username << " deleted." << endl;
                break;
            case 6: //quit
                
                cout << "Back to main menu? [y] to go back, anyother key to quit." << endl;
                cin >> goback;
                
                if (goback.compare("y") == 0) {
                    Util::printMenu();
                    cin >> selection;
                } else {
                    cout << "see ya later alligator! " << endl;
                }
                play = false;
                break;
                
            default:
                play = true;
                break;
                
        }//switch
    }//while
}//main
