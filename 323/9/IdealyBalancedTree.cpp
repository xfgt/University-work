//
// Created by MRSLAVE on 09-Dec-24.
//
//
// Created by MRSLAVE on 09-Dec-24.
//

#include <iostream>
#include "traversal.h"

int n{};

po ibd(int n) {
    po darj;
    DataT x;


    if(n>0) {
        int nl = n / 2;
        int nd = n - nl - 1;
        darj = new node;
    // normal
        std::cin >> x;
        darj->data = x;

        darj->left = ibd(nl);
    // infix
        // std::cin >> x;
        // darj->data = x;

        darj->right= ibd(nd);
    // postfix
        // std::cin >> x;
        // darj->data = x;


        return darj;
    } else return nullptr;

}


int main() {
    po root;
    std::cin >> n;
    root = ibd(n);
    print(root, 1);

    printf("Prefix\n");
    Preorder_prefix_NLR(root);

    printf("\nInfix\n");
    Inorder_infix_LNR(root);

    printf("\nPostfix\n");
    Postorder_postfix_LRN(root);



}


