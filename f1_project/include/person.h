#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
using namespace std;

class Person {
private:
    string firstName;
    string lastName;
    int age;

public:
    // Конструктор
    Person(const string& fName, const string& lName, int age);
    
    // Виртуальный деструктор
    virtual ~Person();
    
    // Геттеры
    string getFirstName() const;
    string getLastName() const;
    int getAge() const;
    
    // Сеттеры
    void setFirstName(const string& fName);
    void setLastName(const string& lName);
    void setAge(int newAge);
    
    // Чисто виртуальная функция (делает класс абстрактным)
    virtual void work() const = 0;
    
    // Обычная виртуальная функция для вывода информации
    virtual void showInfo() const;
};

#endif