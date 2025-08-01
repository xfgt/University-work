#include "Person.h"

Person::Person() {
    m_name = "";
    m_proposalIndex = 0;
    m_currentPartner = "";
}

Person::Person(const std::string& name) : 
    m_name(name), m_proposalIndex(0), m_currentPartner("") {}

void Person::setPreferences(const std::vector<std::string>& prfs) {
    m_partnerPreferences = prfs;
    for (int i = 0; i < prfs.size(); ++i) {
        m_ranklist[prfs[i]] = i;
    }
}

std::string Person::getNextProposal() {
    if (m_proposalIndex < m_partnerPreferences.size()) {
        return m_partnerPreferences[m_proposalIndex++];
    }
    return "";
}

void Person::rejectCurrent() {
    m_currentPartner = "";
}

bool Person::prefers(const std::string& newPartner) const {
    return m_ranklist.at(newPartner) < m_ranklist.at(m_currentPartner);
}
