#ifndef PARSE_COMPANIES_H
#define PARSE_COMPANIES_H

#include <string>
#include <vector>
#include <sstream>
#include <set>

#include "Company.h"

Company* parseUniqueCompanies(std::string companiesString, int& numParsedCompanies, std::string(&getUniqueIdentifier)(const Company&)) {
	std::istringstream companiesIn(companiesString);

	numParsedCompanies = 0;

	std::set<std::string> parsedUnique;
	std::vector<Company> companies;

	std::string companyLine;
	while (std::getline(companiesIn, companyLine)) {
		std::istringstream companyLineIn(companyLine);

		int id; std::string name;
		companyLineIn >> id >> name;

		Company company(id, name);
		std::string uniqueIdentifier = getUniqueIdentifier(company);


		if (parsedUnique.find(uniqueIdentifier) == parsedUnique.end()) {
			companies.push_back(company);
			parsedUnique.insert(uniqueIdentifier);
		}
	}


	numParsedCompanies = companies.size();


	Company* companiesPtr = new Company[companies.size()];

	for (int i = 0; i < companies.size(); i++) {
		companiesPtr[i] = companies[i];
	}

	return companiesPtr;
}

#endif // !PARSE_COMPANIES_H
