//
// Created by MRSLAVE on 09-Dec-24.
//
//
// Created by MRSLAVE on 09-Dec-24.
//
#include <iostream>
typedef char DataT;
typedef struct node* po;

struct node {
    DataT data;
    po left;
    po right;
};

int COUNT{};

po ibd(int);
void Preorder_prefix_NLR(po);
void Inorder_infix_LNR(po);
void Postorder_postfix_LRN(po);
void print(po, int);


int main() {
    int n; po root;
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


po ibd(int n) {
    po darj;
    DataT x;


    if(n>0) {
        int nl = n / 2;
        int nd = n - nl - 1;
        darj = new node;
        std::cin >> x; darj->data = x;
        // !
        darj->left = ibd(nl);
        darj->right= ibd(nd);
        return darj;
    } else {
        return nullptr;
    }


}

void Preorder_prefix_NLR(po help) {
    if(help) {
        std::cout << help->data;
        Inorder_infix_LNR(help->left);
        Inorder_infix_LNR(help->right);
    }

}
void Inorder_infix_LNR(po help) {

    if(help) {
        std::cout << "(";
        Inorder_infix_LNR(help->left);
        std::cout << help->data;
        Inorder_infix_LNR(help->right);
        std::cout << ")";
    }


}
void Postorder_postfix_LRN(po help) {
    if(help) {
        Inorder_infix_LNR(help->left);
        Inorder_infix_LNR(help->right);
        std::cout << help->data;
    }

}


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
