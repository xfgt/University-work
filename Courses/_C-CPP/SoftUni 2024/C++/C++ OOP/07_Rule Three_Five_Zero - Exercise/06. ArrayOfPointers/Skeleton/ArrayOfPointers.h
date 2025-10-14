//
// Created by twister on 8/21/24.
//

#ifndef ARRAYOFPOINTERS_H
#define ARRAYOFPOINTERS_H


#include <vector>




struct ArrayOfPointers{

    std::vector<Company*> mxV;


    void add(Company* pObj){
        mxV.push_back(pObj);
    }
    Company* get(const size_t& index){
        return mxV.at(index);
    }

    size_t getSize() const { return mxV.size(); }

};






#endif //ARRAYOFPOINTERS_H
