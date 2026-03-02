#include "../include/team.h"

Team::Team(const string& name, const string& location, int founded, double budg) {
    setTeamName(name);
    setBaseLocation(location);
    setYearFounded(founded);
    setBudget(budg);
    setChampionshipsWon(0);
    
    // Инициализируем указатели нулем
    mainDriver = nullptr;
    reserveDriver = nullptr;
    principal = nullptr;
    techDirector = nullptr;
    
    cout << "\n=========================================" << endl;
    cout << "  [CONSTRUCTOR] TEAM: " << teamName << " CREATED" << endl;
    cout << "=========================================\n" << endl;
}

Team::~Team() {
    cout << "\n=========================================" << endl;
    cout << "  [DESTRUCTOR] TEAM: " << teamName << " DESTROYED" << endl;
    cout << "=========================================\n" << endl;
    
    // Удаляем все созданные объекты
    delete mainDriver;
    delete reserveDriver;
    delete principal;
    delete techDirector;
    
    for (RaceEngineer* re : raceEngineers) {
        delete re;
    }
    
    for (Mechanic* m : mechanics) {
        delete m;
    }
}

// Геттеры
string Team::getTeamName() const { return teamName; }
string Team::getBaseLocation() const { return baseLocation; }
int Team::getYearFounded() const { return yearFounded; }
double Team::getBudget() const { return budget; }
int Team::getChampionshipsWon() const { return championshipsWon; }

// Сеттеры
void Team::setTeamName(const string& name) { teamName = name; }
void Team::setBaseLocation(const string& location) { baseLocation = location; }
void Team::setYearFounded(int year) { yearFounded = year; }
void Team::setBudget(double budg) { if (budg >= 0) budget = budg; }
void Team::setChampionshipsWon(int champs) { championshipsWon = champs; }

void Team::setMainDriver(Driver* driver) { mainDriver = driver; }
void Team::setReserveDriver(Driver* driver) { reserveDriver = driver; }
void Team::setPrincipal(TeamPrincipal* tp) { principal = tp; }
void Team::setTechDirector(TechnicalDirector* td) { techDirector = td; }
void Team::addRaceEngineer(RaceEngineer* re) { raceEngineers.push_back(re); }
void Team::addMechanic(Mechanic* m) { mechanics.push_back(m); }

void Team::showTeamInfo() const {
    cout << "\n╔══════════════════════════════════════════════════════╗" << endl;
    cout << "║           TEAM " << teamName << " PROFILE" << endl;
    cout << "╠══════════════════════════════════════════════════════╣" << endl;
    cout << "║  Base: " << baseLocation << endl;
    cout << "║  Founded: " << yearFounded << " | Budget: $" << budget << "M" << endl;
    cout << "║  Championships: " << championshipsWon << endl;
    cout << "╚══════════════════════════════════════════════════════╝" << endl;
    
    cout << "\n--- TEAM MANAGEMENT ---" << endl;
    if (principal) {
        cout << "  ■ ";
        principal->showInfo();
        principal->work();
    }
    
    if (techDirector) {
        cout << "  ■ ";
        techDirector->showInfo();
        techDirector->work();
    }
    
    cout << "\n--- DRIVERS ---" << endl;
    if (mainDriver) {
        cout << "  ★ MAIN: ";
        mainDriver->showInfo();
        mainDriver->work();
    }
    
    if (reserveDriver) {
        cout << "  ☆ RESERVE: ";
        reserveDriver->showInfo();
        reserveDriver->work();
    }
    
    cout << "\n--- RACE ENGINEERS (" << raceEngineers.size() << ") ---" << endl;
    for (size_t i = 0; i < raceEngineers.size(); ++i) {
        cout << "  " << i+1 << ". ";
        raceEngineers[i]->showInfo();
        raceEngineers[i]->work();
    }
    
    cout << "\n--- MECHANICS (" << mechanics.size() << ") ---" << endl;
    for (size_t i = 0; i < mechanics.size(); ++i) {
        cout << "  " << i+1 << ". ";
        mechanics[i]->showInfo();
        mechanics[i]->work();
    }
    cout << endl;
}

void Team::prepareForRace() const {
    cout << "\n>>> TEAM " << teamName << " PREPARING FOR RACE <<<" << endl;
    if (principal) principal->work();
    if (techDirector) techDirector->work();
    if (mainDriver) mainDriver->work();
    cout << ">>> TEAM READY <<<\n" << endl;
}

double Team::calculateTeamStrength() const {
    double strength = 0.0;
    if (mainDriver) strength += mainDriver->getPointsScored() / 100.0;
    if (principal) strength += principal->getExperienceYears() * 0.5;
    if (techDirector) strength += techDirector->getYearsInF1() * 0.3;
    strength += raceEngineers.size() * 2.0;
    strength += mechanics.size() * 1.5;
    return strength;
}