#pragma once 

#include <vector>
#include <string>
#include <unordered_map>

struct Person {

    std::string m_name;
    std::vector<std::string> m_partnerPreferences;
    std::unordered_map<std::string, int> m_ranklist;
    std::string m_currentPartner;
    int m_proposalIndex;

    Person();
    Person(const std::string& name);
    void setPreferences(const std::vector<std::string>& prfs);
    std::string getNextProposal();
    void rejectCurrent();
    bool prefers(const std::string& newPartner) const;
};

