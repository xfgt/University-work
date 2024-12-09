//
// Created by MRSLAVE on 09-Dec-24.
//
#include <iostream>
typedef int DataT;
typedef struct node* po;

struct node {
    DataT data;
    po left;
    po right;
};

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

int main() {
    int n; po root;
    std::cin >> n;
    root = ibd(n);
}