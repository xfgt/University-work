//
// Created by MRSLAVE on 10-Binary-search-tree-Dec-24.
//

#pragma once

typedef char DataT;
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
