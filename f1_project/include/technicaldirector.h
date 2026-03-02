#ifndef TECHNICALDIRECTOR_H
#define TECHNICALDIRECTOR_H

#include "person.h"

class TechnicalDirector : public Person {
private:
    string specialization;
    int yearsInF1;
    int carsDesigned;      // свои поля

public:
    TechnicalDirector(const string& fName, const string& lName, int age,
                      const string& spec, int years, int cars = 0);
    
    ~TechnicalDirector();
    
    // Геттеры
    string getSpecialization() const;
    int getYearsInF1() const;
    int getCarsDesigned() const;
    
    // Сеттеры
    void setSpecialization(const string& spec);
    void setYearsInF1(int years);
    void setCarsDesigned(int cars);
    
    void work() const override;
    void showInfo() const override;
};

#endif