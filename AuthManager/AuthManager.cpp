#include "AuthManager.h"

namespace upgrade{



    AuthManager::AuthManager() : m_currentUser(""), m_isLoggedIn(false){}

    AuthManager::bool registerUser(const std::string& username, const std::string& password){
       bool success = false;

       //check if user already exists
       if(m.users.count(username) == 0){
        //hash password 
        std::string hashedPassword = hashPassword(password);

        //store user 
        m_users[username] = hashedPassword;

        success = true;
       }

       return success;
    }





}