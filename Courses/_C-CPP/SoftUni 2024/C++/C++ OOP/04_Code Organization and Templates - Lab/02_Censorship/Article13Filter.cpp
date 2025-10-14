//
// Created by twister on 7/17/24.
//


#include "Article13Filter.h"

Article13Filter::Article13Filter(std::set<std::string> copyrighted){
    this->copyrighted = std::move(copyrighted);
}

bool Article13Filter::blockIfCopyrighted(std::string s){
    bool hasBad = false;
    for(const auto& it : this->copyrighted){
        if(s == it){
            blocked.push_back(s);
            hasBad = true;
        }
    }
    return hasBad;
}


bool Article13Filter::isCopyrighted(std::string s){
    for(const auto& it : this->copyrighted)
        if(s == it)
            return true;

    return false;
}

std::vector<std::string> Article13Filter::getBlocked(){ return blocked; }


