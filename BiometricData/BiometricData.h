#ifndef UPGRADE_BIOMETRICDATA_H
#define UPGRADE_BIOMETRICDATA_H

#include <iostream> 
#include <string> 

namespace upgrade {

    enum class ActivityLevel{
        LOW,
        MEDIUM, 
        HIGH
    };

    class BiometricData{
    
        private: 
        int m_heartRate;
        ActivityLevel m_activityLevel;

        public: 
        BiometricData(int heartRate, ActivityLevel activityLevel);

        //getters
        int getHeartRate() const;
        ActivityLevel getActivityLevel() const;

        std::string getMood() const;

    };
}
#endif