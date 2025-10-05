//
// Created by twister on 7/13/24.
//
#include "MemoryAllocator.h"

#include <ext/concurrence.h>

enum Action{
    NOTHING = -1,
    ALLOCATE = 0,
    DEALLOCATE,
    IDLE
};


extern ErrorCode executeCommand(const std::string& command, std::vector<int*>& memory){
    Action enumAct;
    std::string actionStr;
    int x{};

    std::stringstream ssInput(command);
    ssInput >> actionStr;


    if (actionStr == "Allocate")
        enumAct = ALLOCATE;
    else if (actionStr == "Deallocate")
        enumAct = DEALLOCATE;
    else if (actionStr == "Idle")
        enumAct = IDLE;
    else
        enumAct = NOTHING;



    switch (enumAct){
    case ALLOCATE:  // pulni
        ssInput >> x;


        if (x <= 0) return MEMORY_LEAK;


        if(memory.size() - x > 0 && memory.size() - x < memory.capacity()){
            for(int i = 0; i <= x; i++){
                memory.pop_back();
            }
            return EXECUTE_SUCCESS;
        } else {
            return MEMORY_LEAK;
        }
        break;









    case DEALLOCATE: // prazni
        ssInput >> x;
        if(x <= 0) DOUBLE_FREE;
        if(x > memory.capacity()) return INDEX_OUT_OF_BOUND;
        if (memory.size() == memory.capacity()){
            return DOUBLE_FREE;
        }

        if(memory.size() + x <= memory.capacity()){
            for(int i = 0; i <= x; i++){
                memory.push_back(nullptr);
            }
            return EXECUTE_SUCCESS;
        } else{
            return DOUBLE_FREE;
        }
        break;











    case IDLE: return EXECUTE_IDLE;
    case NOTHING: std::cout << std::endl; break;

    default: break;


    }
}

extern void printResult(const ErrorCode errorCode, const std::string& command){
    /*
        *➢ For successful allocation/deallocation (not introducing memory leak or crashing the problem) –
        “command - success”
        ➢ For preventing a memory leak – “command - memory leak prevented, will not make allocation”
        ➢ For preventing a system crash – “command - system crash prevented, will skip this deallocation”
        ➢ For receiving an index that is not in the bound of your memory allocator – “command – out of bound”
        ➢ For receiving an “Idle” – “command - this exam is a piece of cake! Where is the OOP already?!?
        */

    switch (errorCode){
    case EXECUTE_SUCCESS:
        std::cout << command << " - success" << std::endl;
        break;

    case EXECUTE_IDLE:
        std::cout << command << " - this exam is a piece of cake! Where is the OOP already?!?" << std::endl;
        break;

    case MEMORY_LEAK:
        std::cout << command << " - memory leak prevented, will not make allocation" << std::endl;
        break;

    case DOUBLE_FREE:
        std::cout << command << " - system crash prevented, will skip this deallocation" << std::endl;
        break;

    case INDEX_OUT_OF_BOUND:
        std::cout << command << " - out of bound" << std::endl;
        break;

    default:
        break;
    }
}
