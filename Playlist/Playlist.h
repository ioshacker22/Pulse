#ifndef UPGRADE_PLAYLIST_H
#define UPGRADE_PLAYLIST_H

#include <iostream> 
#include <string> 
#include <vector>
#include <cstddef>
#include <fstream> 
#include "Song.h"

namespace upgrade{

    class Playlist{

        private: 
        std::string m_playlistName;
        std::vector<Song> m_songs;

        public: 
        Playlist(const std::string& name);
        void addSong(const Song& song); 
        bool removeSong(const std::string& title); //removes song by title
        void display() const; // prints playlist name and all songs 

        //getters
        std::string getName() const; // returns playlistName
        const std::vector<Song>& getSongs() const; // returns reference to song collection 
       

        //utilities
        bool isEmpty() const;
        size_t size() const; //returns how many songs are in it

        //save playlist to a file
        void saveToFile(const std::string& filename) const;

        //load playlist from a file
        void loadFromFile(const std::string& filename);

    };
}

#endif