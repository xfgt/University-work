//
// Created by twister on 7/30/24.
//

#ifndef PROFITREPORT_H
#define PROFITREPORT_H


#include "Company.h"
#include "ProfitCalculator.h"
#include <map>
#include <sstream>


struct getProfitReport{
    friend std::ostream& operator << (std::ostream&, const getProfitReport&);


    std::map<std::string, int> m_results;

    const Company* m_start;
    const Company* m_finish;
    typedef std::map<int, ProfitCalculator> theMap;
    theMap& m_data;
    std::ostringstream m_cOut;

    explicit getProfitReport(const Company* start, const Company* finish, theMap& data) :
        m_start(start),
        m_finish(finish),
        m_data(data) {


        // follow exact order!

        for(auto comp = m_start; comp != m_finish+1; comp++){

            for(const auto& it : m_data){
                if(it.first == comp->getId()) {
                    m_cOut << comp->getName() << " = " << it.second.calculateProfit(*comp) << std::endl;
                    break;
                }
            }


        }



    }// !Constructor

};

inline std::ostream& operator << (std::ostream& OUT, const getProfitReport& obj ) {
    OUT << obj.m_cOut.str();
    return OUT;

}







#endif //PROFITREPORT_H
