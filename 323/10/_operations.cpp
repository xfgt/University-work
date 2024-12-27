//
// Created by MRSLAVE on 27-Dec-24.
//
#include <iostream>
#include "_operations.h"
struct node *newNode(int item) {
    struct node *temp = (struct node *) malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = nullptr;
    return temp;
}

struct node *minValueNode(struct node *node) {
    struct node* current = node;

    while(current && current->left != nullptr)
        current = current->left;

    return current;
}

struct node *insert (struct node *node, int key) {
    if(node == nullptr) return newNode(key);

    if(key < node->key)     node->left = insert(node->left, key);
    else                    node->right = insert(node->right, key);

    return node;
}

struct node *deleteNode(struct node *root, int key) {
    if(root == nullptr) return root;

    if(key < root->key)         root->left = deleteNode(root->left, key);
    else if(key > root->key)    root->right = deleteNode(root->right, key);
    else {

        if(root->left == nullptr) {
            struct node *temp = root->right;
            free(root);
            return temp;
        } else if(root->right == nullptr) {
            struct node *temp = root->left;
            free(root);
            return temp;
        }


        struct node *temp = minValueNode(root->right);

        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);

    }

    return root;
}

void inorder(struct node* root) {
    if(root == nullptr) return;

    inorder(root->left);
    std::cout << root->key << " -> ";
    inorder(root->right);
}

int COUNT{};
void print(struct node *root, int space)
{
    COUNT = 10;
    if (root == nullptr) return;

    space += COUNT;
    print(root->right, space);

    std::cout << std::endl;
    for (int i = COUNT; i < space; i++)
        std::cout << " ";
    std::cout << root->key << "\n";

    print(root->left, space);
}