#ifndef RACEENGINEER_H
#define RACEENGINEER_H

#include "person.h"
#include "driver.h"

class RaceEngineer : public Person {
private:
    Driver* assignedDriver;  // указатель на пилота
    int yearsExperience;
    string specialtyArea;    // свои поля

public:
    RaceEngineer(const string& fName, const string& lName, int age,
                 Driver* driver, int years, const string& area = "Race Strategy");
    
    ~RaceEngineer();
    
    // Геттеры
    Driver* getAssignedDriver() const;
    int getYearsExperience() const;
    string getSpecialtyArea() const;
    
    // Сеттеры
    void setAssignedDriver(Driver* driver);
    void setYearsExperience(int years);
    void setSpecialtyArea(const string& area);
    
    void work() const override;
    void showInfo() const override;
};

#endif