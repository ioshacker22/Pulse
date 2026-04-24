#include "BiometricData.h"

namespace upgrade{


    BiometricData::BiometricData(int heartRate, ActivityLevel activityLevel) 
    : m_heartRate(heartRate), m_activityLevel(activityLevel){}

    int BiometricData::getHeartRate() const{
        return m_heartRate;
    }

    ActivityLevel BiometricData::getActivityLevel() const{
        return m_activityLevel;
    }

    std::string BiometricData::getMood() const{
        std::string mood;
        if(m_heartRate > 150){
           mood = "energetic";
        }else if (m_heartRate > 100){
            mood = "focused";
        }else if (m_heartRate > 80){
            mood = "calm";
        }else{
            mood = "sleepy";
        }
        return mood;
    }
}
