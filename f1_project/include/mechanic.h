#ifndef MECHANIC_H
#define MECHANIC_H

#include "person.h"

class Mechanic : public Person {
private:
    string specialization;
    double pitStopSpeed;    // время пит-стопа в секундах
    int yearsInTeam;        // свои поля

public:
    Mechanic(const string& fName, const string& lName, int age,
             const string& spec, double pitSpeed, int years = 0);
    
    ~Mechanic();
    
    // Геттеры
    string getSpecialization() const;
    double getPitStopSpeed() const;
    int getYearsInTeam() const;
    
    // Сеттеры
    void setSpecialization(const string& spec);
    void setPitStopSpeed(double speed);
    void setYearsInTeam(int years);
    
    void work() const override;
    void showInfo() const override;
};

#endif