//
// Created by twister on 8/2/24.
//

#ifndef WORD_H
#define WORD_H

#include <cstring>
#include <map>



struct Word{
    std::string m_wrd;
    int m_count{};
    static std::map<std::string, int> m_xm; //!!!

    explicit Word(std::string& x)
        :m_wrd(x){

        if(find(x)){
            m_xm.at(m_wrd)++;
        } else{
            m_xm[m_wrd] = ++m_count;

        }


    }

    bool find(std::string& x) const {
        for(const auto& it : m_xm){
            if(it.first == x){
                return true;
            }
        }
        return false;
    }

    std::string getWord() const{
        return m_wrd;
    }
    int getCount() const{ // !!!
        int temp = m_xm[m_wrd];
        m_xm.erase(m_wrd);
        return temp;
    }


    bool operator<(const Word& sample) const {
        // if(sample.word == this.word) sample.m_count++;
        return (std::strcmp(this->getWord().c_str(), sample.getWord().c_str()) < 0);
    }
};
std::map<std::string, int> Word::m_xm;

#endif //WORD_H
