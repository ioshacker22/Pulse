#include "Recommendation.h"

namespace upgrade{

    Recommendation::Recommendation(const std::vector<Song>& catalogue) : m_catalogue(catalogue){}

    void Recommendation::addSong(const Song& song){
        m_catalogue.push_back(song);
    }

    std::vector<Song> Recommendation::recommend(const User& user, const BiometricData& data) const {
        std::vector<Song> results;
        std::string mood = data.getMood();

        // Loop through catalogue
        for (const Song& song : m_catalogue) {

            bool inHistory = false;

            // Loop through user's history
            for (const Song& played : user.getHistory()) {
                if (played.getTitle() == song.getTitle()) {
                    inHistory = true;
                    break;  // stop once found
                }
            }

            // Apply conditions
            if (song.getMoodTag() == mood && !inHistory) {
                results.push_back(song);
            }
        }

        return results;  
    }


    void Recommendation::displayRecommendations(const User& user, const BiometricData& data) const{
        std::vector<Song> results = recommend(user, data);

            if (results.empty()) {
                std::cout << "No recommendations available.\n";
            } 
            else {
                std::cout << "Recommended Songs:\n";
                std::cout << "------------------\n";

            for (const Song& song : results) {
                song.display();
                std::cout << "------------------\n";
            }
        }

    }




}