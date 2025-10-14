//
// Created by twister on 7/28/24.
//

#ifndef FIND_H
#define FIND_H

#include "Company.h"

Company* find( std::vector<Company*>& xv, const int& id ){

    for(const auto& it : xv){
        if(it->getId() == id){
            return it;
        }
    }

    return nullptr;
}

#endif //FIND_H
