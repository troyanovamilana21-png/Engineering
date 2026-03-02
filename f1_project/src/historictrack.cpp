#include "../include/historictrack.h"
#include <ctime>

HistoricTrack::HistoricTrack(const string& trackName, const string& trackCountry,
                             double trackLength, int trackTurns,
                             int built, bool mod, int firstGP, const string& hist)
    : Track(trackName, trackCountry, trackLength, trackTurns) {
    setYearBuilt(built);
    setModified(mod);
    setFirstGrandPrix(firstGP);
    setHeritage(hist);
    cout << "   [CONSTRUCTOR] HistoricTrack: " << getName() << endl;
}

HistoricTrack::~HistoricTrack() {
    cout << "   [DESTRUCTOR] HistoricTrack: " << getName() << endl;
}

int HistoricTrack::getYearBuilt() const { return yearBuilt; }
bool HistoricTrack::getModified() const { return modified; }
int HistoricTrack::getFirstGrandPrix() const { return firstGrandPrix; }
string HistoricTrack::getHeritage() const { return heritage; }

void HistoricTrack::setYearBuilt(int built) { yearBuilt = built; }
void HistoricTrack::setModified(bool mod) { modified = mod; }
void HistoricTrack::setFirstGrandPrix(int firstGP) { firstGrandPrix = firstGP; }
void HistoricTrack::setHeritage(const string& hist) { heritage = hist; }

void HistoricTrack::getTrackType() const {
    cout << getName() << " - HISTORIC CIRCUIT";
    if (getAge() > 50) cout << " (Classic)";
    cout << endl;
}

void HistoricTrack::showInfo() const {
    Track::showInfo();
    cout << ", Type: Historic Circuit"
         << ", Built: " << yearBuilt
         << ", Modified: " << (modified ? "Yes" : "No")
         << ", First GP: " << firstGrandPrix
         << ", Heritage: " << heritage << endl;
}

int HistoricTrack::getAge() const {
    time_t t = time(0);
    tm* now = localtime(&t);
    int currentYear = now->tm_year + 1900;
    return currentYear - yearBuilt;
}