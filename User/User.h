#ifndef UPGRADE_USER_H
#define UPGRADE_USER_H

#include <iostream> 
#include <string> 
#include <vector> 
#include "Song.h"

namespace upgrade{

    class User{
        private: 
        std::string m_username; 
        std::string m_password; 
        std::vector<Song> m_favourite; 
        std::vector<Song> m_history; 
        

        public: 
        User(const std::string& username, const std::string& password);

       void addToFavourites(const Song& song);
        

        //getters
        std::string getUsername() const; //returns username
        std::string getPassword() const;  // returns password
        void addToHistory(const Song& song); //adds a song to the history
        void displayHistory() const; // loops through history and displays song
        void displayFavourites() const;  // loops through m_favourite and displays song
        const std::vector<Song>& getHistory() const; //returns hostory
        const std::vector<Song>& getFavourites() const;  //returns  favoourites


    };
}
#endif