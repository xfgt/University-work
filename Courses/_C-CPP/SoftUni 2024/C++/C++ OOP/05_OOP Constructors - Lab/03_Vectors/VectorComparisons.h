//
// Created by twister on 7/28/24.
//



#ifndef VECTORCOMPARISONS_H
#define VECTORCOMPARISONS_H

#include "Vector.h"

struct VectorLengthComparer{
    bool operator()(const Vector& obj_A, const Vector& obj_B) const{
        return obj_A.getLength() < obj_B.getLength();
    }
};


template<typename T, typename R>
struct ReverseComparer{
    bool operator()(const T& lhs, const T& rhs) const{
        R v;
        return !v(lhs, rhs);
    }
};




#endif //VECTORCOMPARISONS_H
