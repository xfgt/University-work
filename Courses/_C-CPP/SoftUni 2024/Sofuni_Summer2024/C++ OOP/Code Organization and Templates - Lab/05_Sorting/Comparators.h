//
// Created by twister on 7/21/24.
//

#ifndef COMPARATORS_H
#define COMPARATORS_H

template<typename T> // functor (old lambda)
struct LessThan {
    bool operator()(const T& a, const T& b) const {
        return a < b;
    }
};


template <typename T, class LT>
struct Reverse{
    bool operator()(const T& left, const T& right) const {
        LT lt;
        return !lt(left, right);
    }
};











#endif //COMPARATORS_H
