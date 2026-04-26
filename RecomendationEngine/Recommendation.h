#ifndef UPGRADE_RECOMMENDATION_H
#define UPGRADE_RECOMMENDATION_H

#include <iostream> 
#include <string>
#include <algorithm> 
#include <vector>
#include "Song.h"
#include "User.h"
#include "BiometricData.h"


namespace upgrade {
    class Recommendation{
        private:
        std::vector<Song> m_catalogue;

        public:
        Recommendation(const std::vector<Song>& catalogue); 

        void addSong(const Song& song);  //adds song to catalogue
        std::vector<Song> recommend(const User& user, const BiometricData& data) const; 
        void displayRecommendations(const User& user, const BiometricData& data) const;
        

    };
}
#endif