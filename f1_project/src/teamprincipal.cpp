#include "../include/teamprincipal.h"

TeamPrincipal::TeamPrincipal(const string& fName, const string& lName, int age,
                             int experience, const string& teamName, bool founder)
    : Person(fName, lName, age) {
    setExperienceYears(experience);
    setTeam(teamName);
    setIsFounder(founder);
    cout << "   [CONSTRUCTOR] TeamPrincipal: " << getFirstName() << " " << getLastName() << endl;
}

TeamPrincipal::~TeamPrincipal() {
    cout << "   [DESTRUCTOR] TeamPrincipal: " << getFirstName() << " " << getLastName() << endl;
}

int TeamPrincipal::getExperienceYears() const { return experienceYears; }
string TeamPrincipal::getTeam() const { return team; }
bool TeamPrincipal::getIsFounder() const { return isFounder; }

void TeamPrincipal::setExperienceYears(int years) { experienceYears = years; }
void TeamPrincipal::setTeam(const string& teamName) { team = teamName; }
void TeamPrincipal::setIsFounder(bool founder) { isFounder = founder; }

void TeamPrincipal::work() const {
    cout << "   >> TEAM PRINCIPAL " << getLastName() << ": ";
    cout << "Managing " << team << ", making strategic decisions";
    if (isFounder) cout << " (Team Founder)";
    cout << endl;
}

void TeamPrincipal::showInfo() const {
    Person::showInfo();
    cout << ", Team Principal of " << team
         << ", Experience: " << experienceYears << " years"
         << (isFounder ? ", Founder" : "") << endl;
}