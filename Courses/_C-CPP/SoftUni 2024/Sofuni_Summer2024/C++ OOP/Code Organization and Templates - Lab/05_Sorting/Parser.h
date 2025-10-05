//
// Created by twister on 7/18/24.
//

#ifndef PARSER_H
#define PARSER_H
#include <iostream>
#include <sstream>


template<typename T>
class Parser{

private:
    std::istream& m_IN;
    std::string m_stopLine;

public:
    Parser(std::istream& IN, std::string stopWord) : m_IN(IN), m_stopLine(std::move(stopWord)){}

    bool readNext(T& element) {

        std::string line;

        if (std::getline(m_IN, line) && line != m_stopLine) {
            std::istringstream is(line);
            is >> element;
            return true;
        }

        return false;

    }


};

#endif //PARSER_H
