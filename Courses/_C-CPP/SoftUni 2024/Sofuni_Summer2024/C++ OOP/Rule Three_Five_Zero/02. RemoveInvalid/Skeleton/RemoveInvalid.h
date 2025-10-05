//
// Created by twister on 8/16/24.
//

#ifndef REMOVEINVALID_H
#define REMOVEINVALID_H
#include <random>

inline void removeInvalid(std::list<Company*>& companies_list){

    for(auto& it : companies_list){
        if(it->getId() < 0){
            delete it;
            it = nullptr;
        }
    }

    for(auto& it : companies_list){
        if(it == nullptr){
            companies_list.remove(it);
            break;
        }
    }


}

#endif //REMOVEINVALID_H
