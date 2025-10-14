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
    Parser(std::istream&, std::string& );
    bool readNext(T&);

};

template <class T>
Parser<T>::Parser(std::istream& IN, std::string& stopWord) : m_IN(IN), m_stopLine(std::move(stopWord)){}


template <class T>
bool Parser<T>::readNext(T& n) {


    m_IN >> n;

    std::string currentSong{};
    std::ostringstream oss;
    oss << n;

    std::istringstream sSong(oss.str());
    sSong >> currentSong;

    return currentSong != m_stopLine;


}

#endif //PARSER_H
