#ifndef UPGRADE_SONG_H
#define UPGRADE_SONG_H
#include <iostream> 
#include <string> 

//provides metadata for song recommendation
namespace upgrade{

    class Song{

        private:
        std::string m_title; 
        std::string m_artist; 
        int m_bpm; 
        std::string m_moodTag;
        int m_playCount; 
        bool m_isFavourite;

        public: 
        Song(const std::string& title, const std::string& artist, int heartBPM, const std::string& mood);

        //getters
        std::string getTitle() const;
        std::string getArtist() const;
        int getBpm() const; 
        std::string getMoodTag() const;
        int getPlayCount() const;
        bool getIsFavourite() const;


        void play();
        void markFavourite();
        void display() const;



    };
}

#endif
