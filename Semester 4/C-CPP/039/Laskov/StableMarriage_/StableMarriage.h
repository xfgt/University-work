#pragma once 

#include <map>
#include <string>
#include <vector>
#include "Person.h"

class StableMarriage {
private:
    std::map<std::string, Person> men;
    std::map<std::string, Person> women;
    void readInput(const std::string& filename);

public:
    StableMarriage(const std::string& filename);
    void GaleShapley();
    void printMatches() const;
};
