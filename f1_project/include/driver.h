#ifndef DRIVER_H
#define DRIVER_H

#include "person.h"

class Driver : public Person {
private:
    int driverNumber;
    bool isMainDriver;
    int pointsScored;       // свои поля
    int championshipsWon;   // свои поля

public:
    // Конструктор
    Driver(const string& fName, const string& lName, int age, 
           int number, bool main, int points = 0, int championships = 0);
    
    // Деструктор
    ~Driver();
    
    // Геттеры для своих полей
    int getDriverNumber() const;
    bool getIsMainDriver() const;
    int getPointsScored() const;
    int getChampionshipsWon() const;
    
    // Сеттеры для своих полей
    void setDriverNumber(int number);
    void setIsMainDriver(bool main);
    void setPointsScored(int points);
    void setChampionshipsWon(int championships);
    
    // Переопределение виртуальных функций
    void work() const override;
    void showInfo() const override;
};

#endif