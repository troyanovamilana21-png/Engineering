#include "../include/technicaldirector.h"

TechnicalDirector::TechnicalDirector(const string& fName, const string& lName, int age,
                                     const string& spec, int years, int cars)
    : Person(fName, lName, age) {
    setSpecialization(spec);
    setYearsInF1(years);
    setCarsDesigned(cars);
    cout << "   [CONSTRUCTOR] TechnicalDirector: " << getFirstName() << " " << getLastName() << endl;
}

TechnicalDirector::~TechnicalDirector() {
    cout << "   [DESTRUCTOR] TechnicalDirector: " << getFirstName() << " " << getLastName() << endl;
}

string TechnicalDirector::getSpecialization() const { return specialization; }
int TechnicalDirector::getYearsInF1() const { return yearsInF1; }
int TechnicalDirector::getCarsDesigned() const { return carsDesigned; }

void TechnicalDirector::setSpecialization(const string& spec) { specialization = spec; }
void TechnicalDirector::setYearsInF1(int years) { yearsInF1 = years; }
void TechnicalDirector::setCarsDesigned(int cars) { carsDesigned = cars; }

void TechnicalDirector::work() const {
    cout << "   >> TECHNICAL DIRECTOR " << getLastName() << ": ";
    cout << "Developing new car, specialization: " << specialization;
    if (carsDesigned > 0) cout << " (Designed " << carsDesigned << " cars)";
    cout << endl;
}

void TechnicalDirector::showInfo() const {
    Person::showInfo();
    cout << ", Technical Director, Spec: " << specialization
         << ", F1 Experience: " << yearsInF1 << " years"
         << ", Cars designed: " << carsDesigned << endl;
}