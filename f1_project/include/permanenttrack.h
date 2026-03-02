#ifndef PERMANENTTRACK_H
#define PERMANENTTRACK_H

#include "track.h"

class PermanentTrack : public Track {
private:
    int capacity;
    int pitBuildings;
    bool hasMuseum;          // свои поля
    int yearOpened;          // свои поля

public:
    PermanentTrack(const string& trackName, const string& trackCountry,
                   double trackLength, int trackTurns,
                   int cap, int pits, bool museum, int opened);
    
    ~PermanentTrack();
    
    // Геттеры
    int getCapacity() const;
    int getPitBuildings() const;
    bool getHasMuseum() const;
    int getYearOpened() const;
    
    // Сеттеры
    void setCapacity(int cap);
    void setPitBuildings(int pits);
    void setHasMuseum(bool museum);
    void setYearOpened(int opened);
    
    void getTrackType() const override;
    void showInfo() const override;
    
    // Уникальный метод
    double getCrowdDensity() const;
};

#endif