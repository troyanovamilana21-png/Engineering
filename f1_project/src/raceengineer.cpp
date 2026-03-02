#include "../include/raceengineer.h"

RaceEngineer::RaceEngineer(const string& fName, const string& lName, int age,
                           Driver* driver, int years, const string& area)
    : Person(fName, lName, age) {
    setAssignedDriver(driver);
    setYearsExperience(years);
    setSpecialtyArea(area);
    cout << "   [CONSTRUCTOR] RaceEngineer: " << getFirstName() << " " << getLastName() << endl;
}

RaceEngineer::~RaceEngineer() {
    cout << "   [DESTRUCTOR] RaceEngineer: " << getFirstName() << " " << getLastName() << endl;
}

Driver* RaceEngineer::getAssignedDriver() const { return assignedDriver; }
int RaceEngineer::getYearsExperience() const { return yearsExperience; }
string RaceEngineer::getSpecialtyArea() const { return specialtyArea; }

void RaceEngineer::setAssignedDriver(Driver* driver) { assignedDriver = driver; }
void RaceEngineer::setYearsExperience(int years) { yearsExperience = years; }
void RaceEngineer::setSpecialtyArea(const string& area) { specialtyArea = area; }

void RaceEngineer::work() const {
    cout << "   >> RACE ENGINEER " << getLastName() << ": ";
    if (assignedDriver) {
        cout << "Working with driver #" << assignedDriver->getDriverNumber();
    } else {
        cout << "Analyzing telemetry data";
    }
    cout << " (Specialty: " << specialtyArea << ")" << endl;
}

void RaceEngineer::showInfo() const {
    Person::showInfo();
    cout << ", Race Engineer, Experience: " << yearsExperience << " years"
         << ", Area: " << specialtyArea;
    if (assignedDriver) {
        cout << ", Driver: " << assignedDriver->getLastName();
    }
    cout << endl;
}