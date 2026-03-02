#ifndef TRACK_H
#define TRACK_H

#include <iostream>
#include <string>
using namespace std;

class Track {
private:
    string name;
    string country;
    double length;      // длина круга в км
    int turns;          // количество поворотов

public:
    // Конструктор
    Track(const string& trackName, const string& trackCountry, 
          double trackLength, int trackTurns);
    
    // Виртуальный деструктор
    virtual ~Track();
    
    // Геттеры
    string getName() const;
    string getCountry() const;
    double getLength() const;
    int getTurns() const;
    
    // Сеттеры
    void setName(const string& newName);
    void setCountry(const string& newCountry);
    void setLength(double newLength);
    void setTurns(int newTurns);
    
    // Виртуальные функции
    virtual void getTrackType() const;
    virtual void showInfo() const;
};

#endif