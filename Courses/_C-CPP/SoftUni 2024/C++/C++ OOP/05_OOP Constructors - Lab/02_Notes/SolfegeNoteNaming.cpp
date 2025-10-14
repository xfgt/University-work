//
// Created by twister on 7/28/24.
//
#include "SolfegeNoteNaming.h"




inline char getType(const std::string& x =""){

    if(x == "Do")               return 'C';
    else if(x == "Re")          return 'D';
    else if(x == "Mi")          return 'E';
    else if(x == "Fa")          return 'F';
    else if(x == "Sol")         return 'G';
    else if(x == "La")          return 'A';
    else if(x == "Si")          return 'B';

    return '?';

}


NoteName SolfegeNoteNaming::operator()(const std::string& x) const{
    return getType(x);
}
