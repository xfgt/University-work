//
// Created by twister on 7/14/24.
//

#ifndef MYPARSE_H
#define MYPARSE_H

#include "Defines.h"
#include <iostream>
#include <vector>

extern ErrorCode parseData
(
    const std::string&      ,
    const char*             ,
    const size_t	   	    ,
    std::vector<long long>&
);

extern void printResult
(
    const ErrorCode,
    const std::vector<long long>&
);

#endif //MYPARSE_H
