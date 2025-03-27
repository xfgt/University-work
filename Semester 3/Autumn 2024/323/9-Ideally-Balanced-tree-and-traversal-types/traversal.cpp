//
// Created by MRSLAVE on 10-Binary-search-tree-Dec-24.
//
#include <iostream>
#include "traversal.h"



void Preorder_prefix_NLR(po help) {
    if(help) {
        std::cout << help->data << " ";
        Inorder_infix_LNR(help->left);
        Inorder_infix_LNR(help->right);
    }

}
void Inorder_infix_LNR(po help) {

    if(help) {
    //  std::cout << '(';
        Inorder_infix_LNR(help->left);
        std::cout << help->data << " ";
        Inorder_infix_LNR(help->right);
    //  std::cout << ')';
    }


}
void Postorder_postfix_LRN(po help) {
    if(help) {
        Inorder_infix_LNR(help->left);
        Inorder_infix_LNR(help->right);
        std::cout << help->data << " ";
    }

}

int COUNT{};
void print(po root, int space)
{
    COUNT = 10;
    if (root == NULL)
        return;

    space += COUNT;
    print(root->right, space);
    std::cout << std::endl;
    for (int i = COUNT; i < space; i++)
        std::cout << " ";
    std::cout << root->data << "\n";
    print(root->left, space);
}
