#ifndef HIGHSPEEDTRACK_H
#define HIGHSPEEDTRACK_H

#include "track.h"

class HighSpeedTrack : public Track {
private:
    double averageSpeed;
    int longStraights;
    double maxSpeed;         // свои поля
    bool hasChicanes;        // свои поля

public:
    HighSpeedTrack(const string& trackName, const string& trackCountry,
                   double trackLength, int trackTurns,
                   double avgSpeed, int straights, double maxSp, bool chicanes);
    
    ~HighSpeedTrack();
    
    // Геттеры
    double getAverageSpeed() const;
    int getLongStraights() const;
    double getMaxSpeed() const;
    bool getHasChicanes() const;
    
    // Сеттеры
    void setAverageSpeed(double avgSpeed);
    void setLongStraights(int straights);
    void setMaxSpeed(double maxSp);
    void setHasChicanes(bool chicanes);
    
    void getTrackType() const override;
    void showInfo() const override;
    
    // Уникальный метод
    bool isPowerCircuit() const;
};

#endif