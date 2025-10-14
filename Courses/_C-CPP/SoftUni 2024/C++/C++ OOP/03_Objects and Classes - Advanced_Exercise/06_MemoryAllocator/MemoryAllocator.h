//
// Created by twister on 7/13/24.
//

#ifndef MEMORYALLOCATOR_H
#define MEMORYALLOCATOR_H



#include "Defines.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <string>

extern ErrorCode executeCommand(const std::string&, std::vector<int*>&);
extern void printResult(const ErrorCode, const std::string&);

#endif //MEMORYALLOCATOR_H
