#include "../include/streettrack.h"

StreetTrack::StreetTrack(const string& trackName, const string& trackCountry,
                         double trackLength, int trackTurns,
                         bool temp, bool night, int narrow, const string& center)
    : Track(trackName, trackCountry, trackLength, trackTurns) {
    setIsTemporary(temp);
    setHasNightRace(night);
    setNarrowSections(narrow);
    setCityCenter(center);
    cout << "   [CONSTRUCTOR] StreetTrack: " << getName() << endl;
}

StreetTrack::~StreetTrack() {
    cout << "   [DESTRUCTOR] StreetTrack: " << getName() << endl;
}

bool StreetTrack::getIsTemporary() const { return isTemporary; }
bool StreetTrack::getHasNightRace() const { return hasNightRace; }
int StreetTrack::getNarrowSections() const { return narrowSections; }
string StreetTrack::getCityCenter() const { return cityCenter; }

void StreetTrack::setIsTemporary(bool temp) { isTemporary = temp; }
void StreetTrack::setHasNightRace(bool night) { hasNightRace = night; }
void StreetTrack::setNarrowSections(int narrow) { narrowSections = narrow; }
void StreetTrack::setCityCenter(const string& center) { cityCenter = center; }

void StreetTrack::getTrackType() const {
    cout << getName() << " - STREET CIRCUIT";
    if (isTemporary) cout << " (Temporary)";
    if (hasNightRace) cout << " (Night Race)";
    cout << endl;
}

void StreetTrack::showInfo() const {
    Track::showInfo();
    cout << ", Type: Street Circuit"
         << ", Temporary: " << (isTemporary ? "Yes" : "No")
         << ", Night race: " << (hasNightRace ? "Yes" : "No")
         << ", Narrow sections: " << narrowSections
         << ", City center: " << cityCenter << endl;
}

bool StreetTrack::isDangerousCorner(int cornerNumber) const {
    return (cornerNumber > 0 && cornerNumber <= narrowSections);
}