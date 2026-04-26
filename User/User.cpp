#include "User.h"

namespace upgrade{

    User::User(const std::string& username, const std::string& password)
    : m_username(username), m_password(password){}

    void User::addToFavourites(const Song& song){
       m_favourite.push_back(song);
    }

    std::string User::getUsername() const{
        return m_username;
    }

    std::string User::getPassword() const{
        return m_password;
    }

    void User::addToHistory(const Song& song){
        m_history.push_back(song);
    }

    void User::displayHistory() const{
        if(m_history.empty()){
           std::cout << "No history yet" << std::endl;
           return;
        }

        for(const auto& song : m_history){
           song.display();
        }
    }

    void User::displayFavourites() const{
        if(m_favourite.empty()){
           std::cout << "NO Favourites yet" << std::endl;
           return;
        }

        for(const auto& song : m_favourite){
            song.display();
        }
    }

    const std::vector<Song>& User::getHistory() const{
        return m_history;
    }

    const std::vector<Song>& User::getFavourites() const{
        return m_favourite; 
    }
}