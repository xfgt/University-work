#include "StableMarriage.h"


#include <fstream>
#include <iostream>
#include <queue>
#include <sstream>

StableMarriage::StableMarriage(const std::string& filename) {
    readInput(filename);
}

void StableMarriage::readInput(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cout << "Error opening file " + filename + "!\n";
        return;
    }
     

    int t;
    file >> t; // number of cases

    for (int i = 0; i < t; i++) {
        int n;
        file >> n;
        std::string line;

        std::getline(file, line);
        for (int i = 0; i < n; ++i) {
            std::getline(file, line);
            std::istringstream ss(line);
            std::string name;
            ss >> name;

            Person man(name);
            std::vector<std::string> prefs;
            std::string preference;
            while (ss >> preference)
                prefs.push_back(preference);

            man.setPreferences(prefs);
            men[name] = man;
        }

        for (int i = 0; i < n; ++i) {
            std::getline(file, line);
            std::istringstream ss(line);
            std::string name;
            ss >> name;

            Person woman(name);
            std::vector<std::string> prefs;
            std::string preference;
            while (ss >> preference)
                prefs.push_back(preference);

            woman.setPreferences(prefs);
            women[name] = woman;
        }
        this->GaleShapley();
        this->printMatches();
        this->men.clear();
        this->women.clear();
        std::cout << std::endl;
    }
       
    file.close();
       
    
}

void StableMarriage::GaleShapley() {
    std::queue<std::string> unmatched;
    for (const auto& [name, x] : men) {
        unmatched.push(name);
    }

    while (!unmatched.empty()) {
        std::string manName = unmatched.front();
        unmatched.pop();
        Person& man = men[manName];

        std::string womanName = man.getNextProposal();
        if (womanName.empty()) continue;

        Person& woman = women[womanName];
        if (woman.m_currentPartner.empty()) {

            woman.m_currentPartner = man.m_name;
            man.m_currentPartner = woman.m_name;


        } else if (woman.prefers(man.m_name)) {

            std::string rejected = woman.m_currentPartner;
            men[rejected].rejectCurrent();
            unmatched.push(rejected);

            woman.m_currentPartner = man.m_name;
            man.m_currentPartner = woman.m_name;


        } else {
            unmatched.push(man.m_name);
        }
    }
}

void StableMarriage::printMatches() const {
    for (const auto& [x, man] : men) {
        std::cout << man.m_name << " got matched with " << man.m_currentPartner << "\n";
    }
}
