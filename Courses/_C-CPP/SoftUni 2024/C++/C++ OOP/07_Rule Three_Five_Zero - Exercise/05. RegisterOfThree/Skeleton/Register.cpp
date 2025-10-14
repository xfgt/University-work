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


Register::Register(const Register& other){
    numAdded = other.numAdded;
    companiesArray = other.companiesArray;
}

Register& Register::operator =(const Register& other){
    if(this == &other)
        return *this;

    this->numAdded = other.numAdded;

    if(this->companiesArray != nullptr)
        delete this->companiesArray;

    this->companiesArray = new Company[this->numAdded];

    for(size_t i = 0; i < numAdded; i++){
        this->companiesArray[i] = other.companiesArray[i];
    }

    return *this;
}





