#include "Playlist.h"
#include <algorithm>

namespace upgrade{

    Playlist::Playlist(const std::string& name) : m_playlistName(name){}

    void Playlist::addSong(const Song& song){
        m_songs.push_back(song);
    }

    bool Playlist::removeSong(const std::string& title){
        auto it = std::remove_if(m_songs.begin(), m_songs.end(), [&title](const Song& s){
            return s.getTitle() == title;
        });

        bool found = (it != m_songs.end());
        m_songs.erase(it, m_songs.end());
        return found;
    }

    void Playlist::display() const{
        std::cout << "Playlist Name: " << m_playlistName << std::endl;

        if(m_songs.empty()){
            std::cout << "No playlist available " << std::endl;
            return;
        }

        for(const auto& song : m_songs ){
            song.display();
        }
    }

    std::string Playlist::getName() const{
        return m_playlistName;
    }

    const std::vector<Song>& Playlist::getSongs() const{
        return m_songs;
    }


    bool Playlist::isEmpty() const{
        return m_songs.empty();
    }

    size_t Playlist::size() const{
        return m_songs.size();
    }

    void Playlist::saveToFile(const std::string& filename) const {
        std::ofstream outFile(filename);

        if (outFile.is_open()) {

            // First line: playlist name
            outFile << m_playlistName << "\n";

            // Songs: title,artist,bpm,moodTag
            for (const Song& song : m_songs) {
                outFile
                    << song.getTitle() << ","
                    << song.getArtist() << ","
                    << song.getBpm() << ","
                    << song.getMoodTag() << "\n";
            }

            outFile.close();
        } else {
            std::cout << "Error: Could not open file for writing.\n";
        }
    }


     void Playlist::loadFromFile(const std::string& filename) {
        std::ifstream inFile(filename);

        if (inFile.is_open()) {

            m_songs.clear();  

            // First line: playlist name
            std::getline(inFile, m_playlistName);

            std::string line;

            while (std::getline(inFile, line)) {
                std::stringstream ss(line);

                std::string title, artist, bpmStr, mood;

                std::getline(ss, title, ',');
                std::getline(ss, artist, ',');
                std::getline(ss, bpmStr, ',');
                std::getline(ss, mood, ',');

                // Basic validation
                if (!title.empty() && !artist.empty() && !bpmStr.empty() && !mood.empty()) {
                    int bpm = 0;
                    try {
                        bpm = std::stoi(bpmStr);
                    } catch (...) {
                        continue; 
                    }

                    Song song(title, artist, bpm, mood);
                    addSong(song);
                }
            }

            inFile.close();
        } else {
            std::cout << "Error: Could not open file for reading.\n";
        }
    }





}
