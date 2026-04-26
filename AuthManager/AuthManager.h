#ifndef UPGRADE_AUTHMANAGER_H
#define UPGRADE_AUTHMANAGER_H

#include <iostream> 
#include <string>
#include <functional>
#include <map> 
#include <fstream>

namespace upgrade {

    class AuthManager{
        private:
        std::map<std::string, std::string> m_users; 
        std::string m_currentUser; 
        bool m_isLoggedIn; 

        std::string hashPassword(const std::string& password) const;

        public: 
        AuthManager(); 
        bool registerUser(const std::string& username, const std::string& password);
        bool login(const std::string& username, const std::string& password);
        void logout();
        bool isLoggedIn() const;
        std::string getCurrentUser() const;
        void saveUsers(const std::string& filename) const;
        void loadUsers(const std::string& filename);




    };
}
#endif