//
// Created by twister on 7/31/24.
//
#include "Register.h"

Register::Register(size_t numCompanies){
    numAdded = numCompanies;
    companiesArray = new Company[numAdded];
}

void Register::add(const Company& c){

    for(size_t i = 0; i < numAdded; i++){
        if(companiesArray[i].getName().empty() || companiesArray[i].getId() == 0){
            companiesArray[i] = c;
            return;
        }

    }

}

Company Register::get(int companyId) const{
    for(size_t i = 0; i < numAdded; i++){
        if(companiesArray[i].getId() == companyId){
            return companiesArray[i];
        }
    }
}


Register::~Register(){
    delete[] companiesArray;
}





