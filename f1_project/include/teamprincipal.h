#ifndef TEAMPRINCIPAL_H
#define TEAMPRINCIPAL_H

#include "person.h"

class TeamPrincipal : public Person {
private:
    int experienceYears;
    string team;
    bool isFounder;        // свои поля

public:
    TeamPrincipal(const string& fName, const string& lName, int age,
                  int experience, const string& teamName, bool founder = false);
    
    ~TeamPrincipal();
    
    // Геттеры
    int getExperienceYears() const;
    string getTeam() const;
    bool getIsFounder() const;
    
    // Сеттеры
    void setExperienceYears(int years);
    void setTeam(const string& teamName);
    void setIsFounder(bool founder);
    
    void work() const override;
    void showInfo() const override;
};

#endif