//
// Created by MRSLAVE on 27-Dec-24.
//

//  Binary Search Tree

#include <iostream>
#include "_operations.h"
#include "search.h"


struct node *createTree(int N) {
    struct node *root = nullptr;
    int x;
    while(N--) {
        std::cin >> x;
        root = insert(root, x);
    }
    return root;
}


int main() {
    int SZ;
    std::cin >> SZ;

    struct node *root = createTree(SZ);
    print(root, 1);
    std::cout << "\nInorder traversal: ";
    inorder(root);

    searchInTree(3, root);
    searchInTree(21, root);

    print(root, 1);
    std::cout << "\nInorder traversal: ";
    inorder(root);

    return 0;
}