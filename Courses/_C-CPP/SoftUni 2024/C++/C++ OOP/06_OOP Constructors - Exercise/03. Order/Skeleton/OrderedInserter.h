//
// Created by twister on 7/28/24.
//

#ifndef ORDEREDINSERTER_H
#define ORDEREDINSERTER_H


#include <algorithm>

#include "Company.h"
#include <vector>


struct OrderedInserter{

    const Company* m_last;
    std::vector<const Company*>& m_inputVector;
    std::vector<const Company*>::iterator m_last_iterator;


    explicit OrderedInserter(std::vector<const Company*>& xv) :
    m_inputVector(xv),
    m_last(nullptr),
    m_last_iterator(nullptr){}

    void insert(const Company* x){

        if(m_last == nullptr){
            m_inputVector.push_back(x);
            m_last_iterator = m_inputVector.begin();
            m_last = x;
            return;
        }




        if(x->getId() < m_last->getId()){

            auto pos = m_inputVector.begin();
            for(const auto& j : m_inputVector){
                if(x->getId() < j->getId()){
                    m_inputVector.insert(pos, x);
                    m_last_iterator = pos;
                    break;
                }
                ++pos;
            }

        } else {
            auto h = m_inputVector.begin();
            bool successful = false;

            for(const auto& r : m_inputVector){
                if(r->getId() > x->getId()){
                    m_inputVector.insert(h, x);
                    m_last_iterator = h;
                    successful = true;
                    break;
                }
                ++h;
            }

            if(successful == false){
                m_inputVector.push_back(x);
                m_last_iterator = m_inputVector.end()-1;
            }



        }
        
        m_last = x;
    }



};




#endif //ORDEREDINSERTER_H
