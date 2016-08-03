
#ifndef UsersManager_hpp
#define UsersManager_hpp

#include "Util.hpp"
#include "HighScore.hpp"

#include <stdio.h>
#include <vector>
#include <string>


/*
Utility class for managing file operations for the users.txt file.
 
 Functionality includes:
    Login
    Checking if a user exists in the file.
    Getting the full list of users in the file.
    Sending a single user to the file.
    Updating a user in the file.
*/
class USR_Manager {
    
public:
    static std::vector<HighScore> records;
    static bool checkIfUserExists(Util::User);
    static void sendToFile(Util::User);
    static std::vector<Util::User> getUsersFromFile();
    static Util::User findUserByUsername(std::string);
    static void updateUserHighScore(Util::User);
    static void deleteUser(Util::User);
    
private:
    static int lineCount();
};

#endif /* UsersManager_hpp */
