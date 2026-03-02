#include "../include/highspeedtrack.h"

HighSpeedTrack::HighSpeedTrack(const string& trackName, const string& trackCountry,
                               double trackLength, int trackTurns,
                               double avgSpeed, int straights, double maxSp, bool chicanes)
    : Track(trackName, trackCountry, trackLength, trackTurns) {
    setAverageSpeed(avgSpeed);
    setLongStraights(straights);
    setMaxSpeed(maxSp);
    setHasChicanes(chicanes);
    cout << "   [CONSTRUCTOR] HighSpeedTrack: " << getName() << endl;
}

HighSpeedTrack::~HighSpeedTrack() {
    cout << "   [DESTRUCTOR] HighSpeedTrack: " << getName() << endl;
}

double HighSpeedTrack::getAverageSpeed() const { return averageSpeed; }
int HighSpeedTrack::getLongStraights() const { return longStraights; }
double HighSpeedTrack::getMaxSpeed() const { return maxSpeed; }
bool HighSpeedTrack::getHasChicanes() const { return hasChicanes; }

void HighSpeedTrack::setAverageSpeed(double avgSpeed) { averageSpeed = avgSpeed; }
void HighSpeedTrack::setLongStraights(int straights) { longStraights = straights; }
void HighSpeedTrack::setMaxSpeed(double maxSp) { maxSpeed = maxSp; }
void HighSpeedTrack::setHasChicanes(bool chicanes) { hasChicanes = chicanes; }

void HighSpeedTrack::getTrackType() const {
    cout << getName() << " - HIGH-SPEED CIRCUIT";
    if (averageSpeed > 250) cout << " (Extreme Speed)";
    cout << endl;
}

void HighSpeedTrack::showInfo() const {
    Track::showInfo();
    cout << ", Type: High-Speed Circuit"
         << ", Avg speed: " << averageSpeed << " km/h"
         << ", Long straights: " << longStraights
         << ", Max speed: " << maxSpeed << " km/h"
         << ", Chicanes: " << (hasChicanes ? "Yes" : "No") << endl;
}

bool HighSpeedTrack::isPowerCircuit() const {
    return averageSpeed > 240 && longStraights >= 3;
}