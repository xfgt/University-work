//
// Created by MRSLAVE on 10-Dec-24.
//

#pragma once

typedef int DataT;
typedef struct node* po;

struct node {
    DataT data;
    po left;
    po right;
};



void Preorder_prefix_NLR(po);
void Inorder_infix_LNR(po);
void Postorder_postfix_LRN(po);
void print(po, int);
