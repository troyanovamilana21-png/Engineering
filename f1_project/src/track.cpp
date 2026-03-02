#include "../include/track.h"

Track::Track(const string& trackName, const string& trackCountry, 
             double trackLength, int trackTurns) {
    setName(trackName);
    setCountry(trackCountry);
    setLength(trackLength);
    setTurns(trackTurns);
    cout << "   [CONSTRUCTOR] Track: " << name << " created" << endl;
}

Track::~Track() {
    cout << "   [DESTRUCTOR] Track: " << name << " destroyed" << endl;
}

// Геттеры
string Track::getName() const { return name; }
string Track::getCountry() const { return country; }
double Track::getLength() const { return length; }
int Track::getTurns() const { return turns; }

// Сеттеры
void Track::setName(const string& newName) { name = newName; }
void Track::setCountry(const string& newCountry) { country = newCountry; }
void Track::setLength(double newLength) { if (newLength > 0) length = newLength; }
void Track::setTurns(int newTurns) { if (newTurns > 0) turns = newTurns; }

void Track::getTrackType() const {
    cout << name << " - regular race track" << endl;
}

void Track::showInfo() const {
    cout << "Track: " << name << ", " << country 
         << ", Length: " << length << " km, Turns: " << turns;
}