#ifndef STREETTRACK_H
#define STREETTRACK_H

#include "track.h"

class StreetTrack : public Track {
private:
    bool isTemporary;
    bool hasNightRace;
    int narrowSections;        // свои поля
    string cityCenter;         // свои поля

public:
    StreetTrack(const string& trackName, const string& trackCountry,
                double trackLength, int trackTurns,
                bool temp, bool night, int narrow, const string& center);
    
    ~StreetTrack();
    
    // Геттеры
    bool getIsTemporary() const;
    bool getHasNightRace() const;
    int getNarrowSections() const;
    string getCityCenter() const;
    
    // Сеттеры
    void setIsTemporary(bool temp);
    void setHasNightRace(bool night);
    void setNarrowSections(int narrow);
    void setCityCenter(const string& center);
    
    void getTrackType() const override;
    void showInfo() const override;
    
    // Уникальный метод
    bool isDangerousCorner(int cornerNumber) const;
};

#endif