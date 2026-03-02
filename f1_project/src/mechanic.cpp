#include "../include/mechanic.h"

Mechanic::Mechanic(const string& fName, const string& lName, int age,
                   const string& spec, double pitSpeed, int years)
    : Person(fName, lName, age) {
    setSpecialization(spec);
    setPitStopSpeed(pitSpeed);
    setYearsInTeam(years);
    cout << "   [CONSTRUCTOR] Mechanic: " << getFirstName() << " " << getLastName() << endl;
}

Mechanic::~Mechanic() {
    cout << "   [DESTRUCTOR] Mechanic: " << getFirstName() << " " << getLastName() << endl;
}

string Mechanic::getSpecialization() const { return specialization; }
double Mechanic::getPitStopSpeed() const { return pitStopSpeed; }
int Mechanic::getYearsInTeam() const { return yearsInTeam; }

void Mechanic::setSpecialization(const string& spec) { specialization = spec; }
void Mechanic::setPitStopSpeed(double speed) { 
    if (speed > 0) pitStopSpeed = speed; 
}
void Mechanic::setYearsInTeam(int years) { yearsInTeam = years; }

void Mechanic::work() const {
    cout << "   >> MECHANIC " << getLastName() << ": ";
    cout << "Working on " << specialization;
    if (pitStopSpeed > 0) {
        cout << " (Pit stop time: " << pitStopSpeed << "s)";
    }
    cout << endl;
}

void Mechanic::showInfo() const {
    Person::showInfo();
    cout << ", Mechanic, Spec: " << specialization
         << ", Pit stop: " << pitStopSpeed << "s"
         << ", Years in team: " << yearsInTeam << endl;
}