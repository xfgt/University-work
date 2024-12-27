//
// Created by MRSLAVE on 27-Dec-24.
//

#include <iostream>
#include "_operations.h"


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

    return 0;
}