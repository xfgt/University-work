//
// Created by twister on 8/5/24.
//

#ifndef SEQUENCE_H
#define SEQUENCE_H


#include <vector>


template <typename T, typename Generator>
struct Sequence{
    Generator m_gen;
    std::vector<T> m_xv;

    bool hitZero = false;


    auto begin() { return m_xv.begin(); }  // for-range auto increment
    auto end()  { return m_xv.end()-1; }     // actual value

    Sequence(){
        m_xv.reserve(15); // key
    }

    void generateNext(const int& n){

        if(hitZero) return;


        auto h = m_xv.begin()+1;
        auto s = m_xv.end();


        if(!m_xv.empty()){
            for(auto it = ++h; it!= s; ++it){
                std::cout << *it << ' ';
            }
        }

        m_xv.assign(1, 0); // for-range auto increment for next

        if(n != 0){
            for(int i = 0; i <= n; i++){
                m_xv.push_back(m_gen());
            }
        }
        // no shrink to fit!
        else{
            hitZero = true;
        }











    }

};









#endif //SEQUENCE_H
