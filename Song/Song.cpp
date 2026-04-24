#include "Song.h"

namespace upgrade{

    Song::Song(const std::string& title, const std::string& artist, int heartBPM, const std::string& mood)
    : m_title(title), m_artist(artist), m_bpm(heartBPM), m_moodTag(mood), m_playCount(0), m_isFavourite(false){}

    std::string Song::getTitle() const{
        return m_title;
    }

    std::string Song::getArtist() const{
        return m_artist;
    }

    int Song::getBpm() const{
        return m_bpm;
    }

    std::string Song::getMoodTag() const{
        return m_moodTag;
    }

    int Song::getPlayCount() const{
        return m_playCount;
    }

    bool Song::getIsFavourite() const{
        return m_isFavourite; 
    }

    void Song::play(){
        m_playCount++;
    }

    void Song::markFavourite(){
        m_isFavourite = true;
    }

    void Song::display()const{
        std::cout << "Title: " << m_title << std::endl;
        std::cout << "Artist: " << m_artist << std::endl;
        std::cout << "BPM: " << m_bpm << std::endl;
        std::cout << "Mood: " << m_moodTag << std::endl;
        std::cout << "Play Count: " << m_playCount << std::endl;
        std::cout << "Favorite: " << (m_isFavourite ? "Yes" : "No") << std::endl;
    }




}