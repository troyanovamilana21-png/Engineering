#ifndef TEAM_H
#define TEAM_H

#include "driver.h"
#include "teamprincipal.h"
#include "technicaldirector.h"
#include "raceengineer.h"
#include "mechanic.h"
#include <vector>

class Team {
private:
    string teamName;
    string baseLocation;
    int yearFounded;
    double budget;           // свои поля
    int championshipsWon;     // свои поля
    
    // Указатели на членов команды
    Driver* mainDriver;
    Driver* reserveDriver;
    TeamPrincipal* principal;
    TechnicalDirector* techDirector;
    vector<RaceEngineer*> raceEngineers;
    vector<Mechanic*> mechanics;

public:
    // Конструктор и деструктор
    Team(const string& name, const string& location, int founded, double budg = 0.0);
    ~Team();
    
    // Геттеры
    string getTeamName() const;
    string getBaseLocation() const;
    int getYearFounded() const;
    double getBudget() const;
    int getChampionshipsWon() const;
    
    // Сеттеры
    void setTeamName(const string& name);
    void setBaseLocation(const string& location);
    void setYearFounded(int year);
    void setBudget(double budg);
    void setChampionshipsWon(int champs);
    
    // Методы для добавления членов команды
    void setMainDriver(Driver* driver);
    void setReserveDriver(Driver* driver);
    void setPrincipal(TeamPrincipal* tp);
    void setTechDirector(TechnicalDirector* td);
    void addRaceEngineer(RaceEngineer* re);
    void addMechanic(Mechanic* m);
    
    // Главные методы для демонстрации
    void showTeamInfo() const;
    void prepareForRace() const;
    double calculateTeamStrength() const;
};

#endif