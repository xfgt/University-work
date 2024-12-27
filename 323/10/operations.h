//
// Created by MRSLAVE on 27-Dec-24.
//
#pragma once
struct node {
    int key;
    struct node *left, *right;
};


struct node *newNode(int);
struct node *minValueNode(struct node*);
struct node *insert(struct node*, int);
struct node *deleteNode(struct node*, int);
void inorder(struct node*);
