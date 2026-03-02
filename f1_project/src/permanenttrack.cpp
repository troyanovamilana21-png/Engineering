#include "../include/permanenttrack.h"

PermanentTrack::PermanentTrack(const string& trackName, const string& trackCountry,
                               double trackLength, int trackTurns,
                               int cap, int pits, bool museum, int opened)
    : Track(trackName, trackCountry, trackLength, trackTurns) {
    setCapacity(cap);
    setPitBuildings(pits);
    setHasMuseum(museum);
    setYearOpened(opened);
    cout << "   [CONSTRUCTOR] PermanentTrack: " << getName() << endl;
}

PermanentTrack::~PermanentTrack() {
    cout << "   [DESTRUCTOR] PermanentTrack: " << getName() << endl;
}

int PermanentTrack::getCapacity() const { return capacity; }
int PermanentTrack::getPitBuildings() const { return pitBuildings; }
bool PermanentTrack::getHasMuseum() const { return hasMuseum; }
int PermanentTrack::getYearOpened() const { return yearOpened; }

void PermanentTrack::setCapacity(int cap) { capacity = cap; }
void PermanentTrack::setPitBuildings(int pits) { pitBuildings = pits; }
void PermanentTrack::setHasMuseum(bool museum) { hasMuseum = museum; }
void PermanentTrack::setYearOpened(int opened) { yearOpened = opened; }

void PermanentTrack::getTrackType() const {
    cout << getName() << " - PERMANENT RACING FACILITY";
    if (hasMuseum) cout << " (with Museum)";
    cout << endl;
}

void PermanentTrack::showInfo() const {
    Track::showInfo();
    cout << ", Type: Permanent Circuit"
         << ", Capacity: " << capacity << " spectators"
         << ", Pit buildings: " << pitBuildings
         << ", Museum: " << (hasMuseum ? "Yes" : "No")
         << ", Opened: " << yearOpened << endl;
}

double PermanentTrack::getCrowdDensity() const {
    return static_cast<double>(capacity) / getLength();
}
