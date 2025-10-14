//
// Created by twister on 8/16/24.
//

#ifndef MINBY_H
#define MINBY_H




#include <vector>
#include <algorithm>


struct minBy{


    std::vector<std::string> m_vals;
    typedef bool (*actualFunc)(const std::string& a, const std::string& b);

    explicit minBy(const std::vector<std::string>& v, const actualFunc& f)
        : m_vals(v){
        std::sort(m_vals.begin(), m_vals.end(), f);
    }

    friend std::ostream& operator << (std::ostream&, const minBy&);

};


inline std::ostream& operator << (std::ostream& OUT, const minBy& obj){
    OUT << obj.m_vals.at(0) << std::endl;
    return OUT;
}


#endif //MINBY_H
