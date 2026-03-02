#ifndef HISTORICTRACK_H
#define HISTORICTRACK_H

#include "track.h"

class HistoricTrack : public Track {
private:
    int yearBuilt;
    bool modified;
    int firstGrandPrix;      // свои поля
    string heritage;         // свои поля

public:
    HistoricTrack(const string& trackName, const string& trackCountry,
                  double trackLength, int trackTurns,
                  int built, bool mod, int firstGP, const string& hist);
    
    ~HistoricTrack();
    
    // Геттеры
    int getYearBuilt() const;
    bool getModified() const;
    int getFirstGrandPrix() const;
    string getHeritage() const;
    
    // Сеттеры
    void setYearBuilt(int built);
    void setModified(bool mod);
    void setFirstGrandPrix(int firstGP);
    void setHeritage(const string& hist);
    
    void getTrackType() const override;
    void showInfo() const override;
    
    // Уникальный метод
    int getAge() const;
};

#endif