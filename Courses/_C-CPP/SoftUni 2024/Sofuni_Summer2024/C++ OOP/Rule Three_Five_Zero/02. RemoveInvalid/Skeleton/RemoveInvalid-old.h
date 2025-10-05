//
// Created by twister on 8/16/24.
//

#ifndef REMOVEINVALID_H
#define REMOVEINVALID_H

inline void removeInvalid(std::list<Company*>& companies_list){
    auto nextElement = companies_list.begin();

    for(auto& it : companies_list){
        if(it == nullptr){
            companies_list.remove(it);
            break;
        }
        ++nextElement;

        if(it->getId() < 0){
//          first element
            auto pNext = std::next(nextElement, 0);
            *it = **pNext;
            delete *pNext;
            *pNext = nullptr;

//          others
            while(++nextElement != companies_list.end()){
                if((*nextElement)->getId() >= 0){
                    *pNext++ = new Company(**nextElement);
                }
                delete *nextElement;
                *nextElement = nullptr;
            }

        }


    }


}

#endif //REMOVEINVALID_H
