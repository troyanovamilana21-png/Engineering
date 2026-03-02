#include <iostream>
#include <vector>
#include "include/team.h"
#include "include/driver.h"
#include "include/teamprincipal.h"
#include "include/technicaldirector.h"
#include "include/raceengineer.h"
#include "include/mechanic.h"
#include "include/streettrack.h"
#include "include/permanenttrack.h"
#include "include/highspeedtrack.h"
#include "include/historictrack.h"

using namespace std;

void demonstrateTrackPolymorphism(const vector<Track*>& tracks) {
    cout << "\n========== TRACK POLYMORPHISM DEMONSTRATION ==========" << endl;
    for (const Track* track : tracks) {
        track->getTrackType();  // Виртуальный вызов!
    }
    cout << "==================================================\n" << endl;
}

void demonstratePersonPolymorphism(const vector<Person*>& people) {
    cout << "\n========== PERSON POLYMORPHISM DEMONSTRATION ==========" << endl;
    for (const Person* person : people) {
        person->work();  // Каждый делает свою работу!
    }
    cout << "==================================================\n" << endl;
}

void demonstrateGettersSetters() {
    cout << "\n========== GETTERS/SETTERS DEMONSTRATION ==========" << endl;
    
    // Создаем тестового пилота
    Driver testDriver("Test", "Driver", 25, 99, true, 100, 0);
    
    cout << "Original values:" << endl;
    cout << "  Name: " << testDriver.getFirstName() << " " << testDriver.getLastName() << endl;
    cout << "  Age: " << testDriver.getAge() << endl;
    cout << "  Number: " << testDriver.getDriverNumber() << endl;
    cout << "  Points: " << testDriver.getPointsScored() << endl;
    
    // Используем сеттеры для изменения
    cout << "\nChanging values with setters..." << endl;
    testDriver.setFirstName("Max");
    testDriver.setLastName("Verstappen");
    testDriver.setAge(26);
    testDriver.setDriverNumber(1);
    testDriver.setPointsScored(150);
    
    cout << "New values:" << endl;
    cout << "  Name: " << testDriver.getFirstName() << " " << testDriver.getLastName() << endl;
    cout << "  Age: " << testDriver.getAge() << endl;
    cout << "  Number: " << testDriver.getDriverNumber() << endl;
    cout << "  Points: " << testDriver.getPointsScored() << endl;
    
    cout << "==================================================\n" << endl;
}

int main() {
    cout << "\n╔══════════════════════════════════════════════════════╗" << endl;
    cout << "║        FORMULA 1 TEAM & TRACK SIMULATOR v1.0         ║" << endl;
    cout << "╚══════════════════════════════════════════════════════╝\n" << endl;

    // ===== 1. СОЗДАНИЕ ТРАСС =====
    cout << "\n---------- CREATING TRACKS ----------\n" << endl;
    
    StreetTrack monaco("Monte Carlo", "Monaco", 3.337, 19, 
                       true, true, 5, "Monte Carlo");
    PermanentTrack silverstone("Silverstone", "UK", 5.891, 18, 
                               150000, 7, true, 1948);
    HighSpeedTrack monza("Monza", "Italy", 5.793, 11, 
                         265.0, 3, 372.0, true);
    HistoricTrack spa("Spa-Francorchamps", "Belgium", 7.004, 19, 
                      1921, true, 1950, "Classic Ardennes circuit");
    
    vector<Track*> tracks = {&monaco, &silverstone, &monza, &spa};
    
    // ===== 2. ДЕМОНСТРАЦИЯ ПОЛИМОРФИЗМА ДЛЯ ТРАСС =====
    demonstrateTrackPolymorphism(tracks);
    
    // ===== 3. СОЗДАНИЕ КОМАНДЫ =====
    cout << "\n---------- CREATING FORMULA 1 TEAM ----------\n" << endl;
    
    Team redBull("Red Bull Racing", "Milton Keynes, UK", 2005, 450.0);
    
    // Создаем пилотов
    Driver* max = new Driver("Max", "Verstappen", 26, 1, true, 575, 3);
    Driver* sergio = new Driver("Sergio", "Perez", 34, 11, true, 285, 0);
    Driver* reserve = new Driver("Liam", "Lawson", 22, 40, false, 0, 0);
    
    // Создаем руководство
    TeamPrincipal* horner = new TeamPrincipal("Christian", "Horner", 50, 
                                              18, "Red Bull", false);
    TechnicalDirector* newey = new TechnicalDirector("Adrian", "Newey", 65, 
                                                     "Aerodynamics", 35, 12);
    
    // Создаем инженеров
    RaceEngineer* gp1 = new RaceEngineer("Gianpiero", "Lambiase", 45, 
                                         max, 20, "Race Strategy");
    RaceEngineer* gp2 = new RaceEngineer("Hugh", "Bird", 42, 
                                         sergio, 15, "Performance");
    
    // Создаем механиков
    Mechanic* mech1 = new Mechanic("Jonathan", "Wheatley", 50, 
                                   "Engine", 2.1, 15);
    Mechanic* mech2 = new Mechanic("Phil", "Turner", 38, 
                                   "Suspension", 2.3, 8);
    Mechanic* mech3 = new Mechanic("Steve", "Clark", 45, 
                                   "Gearbox", 2.2, 12);
    
    // Назначаем членов команды
    redBull.setMainDriver(max);
    redBull.setReserveDriver(reserve);
    redBull.setPrincipal(horner);
    redBull.setTechDirector(newey);
    redBull.addRaceEngineer(gp1);
    redBull.addRaceEngineer(gp2);
    redBull.addMechanic(mech1);
    redBull.addMechanic(mech2);
    redBull.addMechanic(mech3);
    
    // ===== 4. ДЕМОНСТРАЦИЯ ГЕТТЕРОВ/СЕТТЕРОВ =====
    demonstrateGettersSetters();
    
    // ===== 5. ДЕМОНСТРАЦИЯ ПОЛИМОРФИЗМА ДЛЯ ЛЮДЕЙ =====
    vector<Person*> people = {max, sergio, horner, newey, gp1, mech1};
    demonstratePersonPolymorphism(people);
    
    // ===== 6. ДЕМОНСТРАЦИЯ РАБОТЫ КОМАНДЫ =====
    cout << "\n---------- TEAM DEMONSTRATION ----------\n" << endl;
    redBull.showTeamInfo();
    redBull.prepareForRace();
    
    cout << "Team strength score: " << redBull.calculateTeamStrength() << endl;
    
    // ===== 7. ДЕМОНСТРАЦИЯ УНИКАЛЬНЫХ МЕТОДОВ ТРАСС =====
    cout << "\n---------- TRACK UNIQUE METHODS ----------\n" << endl;
    cout << "Monaco corner 3 is dangerous? " 
         << (monaco.isDangerousCorner(3) ? "Yes" : "No") << endl;
    cout << "Silverstone crowd density: " 
         << silverstone.getCrowdDensity() << " spectators/km" << endl;
    cout << "Monza is power circuit? " 
         << (monza.isPowerCircuit() ? "Yes" : "No") << endl;
    cout << "Spa circuit age: " << spa.getAge() << " years" << endl;
    
    // ===== 8. ИНФОРМАЦИЯ О ЗАВЕРШЕНИИ =====
    cout << "\n╔══════════════════════════════════════════════════════╗" << endl;
    cout << "║           PROGRAM COMPLETED SUCCESSFULLY              ║" << endl;
    cout << "║         Destructors will now be called...             ║" << endl;
    cout << "╚══════════════════════════════════════════════════════╝\n" << endl;
    
    return 0;
}