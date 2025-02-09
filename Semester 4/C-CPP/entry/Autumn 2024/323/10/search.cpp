//
// Created by MRSLAVE on 21-Dec-24.
//


#include <iostream>
#include "search.h"
#include "_operations.h"


bool missing = false; // insert from the root, not the end

void searchInTree(int x, po loc) {

    if(loc == nullptr || loc->key == x) {
        po& here = loc;
        if(here == nullptr) {
            std::cout << "\n(" << x <<") [" << here << "] -> not in" << std::endl;
            std::cout << "adding " << x << " as a leaf to the tree..." << std::endl;
            missing = true;
        }
        else
            std::cout << "\nElement " << here->key <<" found!\t [" << here << "]" << std::endl;
    }
    else (loc->key > x) ? searchInTree(x, loc->left) : searchInTree(x, loc->right);

    if(missing)
        insert(loc, x);
}

po searchInTreeR(int x, po loc) {
    if(loc==nullptr || loc->key == x) return loc;
     else
         if(loc->key > x) return searchInTreeR(x, loc->right);
            else return searchInTreeR(x, loc->left);
}

// po searchHereIT(int x) {
//     po loc;
//     loc = root;
//     while(loc != nullptr && loc->key != x)
//         (loc->key > x) ? loc = loc->left : loc = loc->right;
//     return loc;
// }