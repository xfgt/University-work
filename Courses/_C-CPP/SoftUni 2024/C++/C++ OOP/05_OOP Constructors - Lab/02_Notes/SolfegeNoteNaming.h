//
// Created by twister on 7/28/24.
//

#ifndef SOLFEGENOTENAMING_H
#define SOLFEGENOTENAMING_H

#include "NoteName.h"
#include <string>

inline char getType(const std::string&);
struct SolfegeNoteNaming{
    NoteName operator()(const std::string&) const;
};



#endif //SOLFEGENOTENAMING_H
