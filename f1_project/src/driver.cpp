#include "../include/driver.h"

Driver::Driver(const string& fName, const string& lName, int age, 
               int number, bool main, int points, int championships)
    : Person(fName, lName, age) {
    setDriverNumber(number);
    setIsMainDriver(main);
    setPointsScored(points);
    setChampionshipsWon(championships);
    cout << "   [CONSTRUCTOR] Driver: " << getFirstName() << " " << getLastName() << endl;
}

Driver::~Driver() {
    cout << "   [DESTRUCTOR] Driver: " << getFirstName() << " " << getLastName() << endl;
}

// Геттеры
int Driver::getDriverNumber() const { return driverNumber; }
bool Driver::getIsMainDriver() const { return isMainDriver; }
int Driver::getPointsScored() const { return pointsScored; }
int Driver::getChampionshipsWon() const { return championshipsWon; }

// Сеттеры
void Driver::setDriverNumber(int number) { 
    if (number > 0 && number < 100) driverNumber = number; 
}
void Driver::setIsMainDriver(bool main) { isMainDriver = main; }
void Driver::setPointsScored(int points) { pointsScored = points; }
void Driver::setChampionshipsWon(int championships) { championshipsWon = championships; }

void Driver::work() const {
    cout << "   >> DRIVER " << getFirstName() << " " << getLastName() << ": ";
    if (isMainDriver) {
        cout << "Racing on track! Number #" << driverNumber;
        if (championshipsWon > 0) {
            cout << " (" << championshipsWon << "x World Champion)";
        }
    } else {
        cout << "Practicing in simulator (Reserve driver)";
    }
    cout << endl;
}

void Driver::showInfo() const {
    Person::showInfo();
    cout << ", Driver #" << driverNumber 
         << " [" << (isMainDriver ? "Main" : "Reserve") << "]"
         << ", Points: " << pointsScored
         << ", Championships: " << championshipsWon << endl;
}