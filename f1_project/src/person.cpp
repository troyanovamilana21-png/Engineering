#include "../include/person.h"

// Конструктор
Person::Person(const string& fName, const string& lName, int age) {
    setFirstName(fName);
    setLastName(lName);
    setAge(age);
    cout << "   [CONSTRUCTOR] Person: " << firstName << " " << lastName << " created" << endl;
}

// Деструктор
Person::~Person() {
    cout << "   [DESTRUCTOR] Person: " << firstName << " " << lastName << " destroyed" << endl;
}

// Геттеры
string Person::getFirstName() const { return firstName; }
string Person::getLastName() const { return lastName; }
int Person::getAge() const { return age; }

// Сеттеры с валидацией
void Person::setFirstName(const string& fName) { 
    if (!fName.empty()) firstName = fName; 
}

void Person::setLastName(const string& lName) { 
    if (!lName.empty()) lastName = lName; 
}

void Person::setAge(int newAge) { 
    if (newAge > 0 && newAge < 120) age = newAge; 
}

// Обычная виртуальная функция
void Person::showInfo() const {
    cout << firstName << " " << lastName << " (Age: " << age << ")";
}