//
// Created by MRSLAVE on 27-Dec-24.
//
#include <iostream>
#include "_operations.h"

struct node *newNode(int item) {
    struct node *temp = (struct node *) malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = nullptr;
    std::cout << "Making a new node!\t [" << &temp << "]\t[" << temp->key << "]" << std::endl;
    return temp;
}

int it{}; // dives in
struct node *insert (struct node *node, int key) {
    if(node == nullptr) {
        std::cout << "[" << &node << "]\t Empty!" <<  std::endl;
        return newNode(key);
    }

    if(key < node->key)         node->left = insert(node->left, key);
    else if(key > node->key)    node->right = insert(node->right, key);
    else                        std::cout << "Item already exists!\t[" << key << "];\t iterations: " << ++it << std::endl;

    return node;
}


struct node *minValueNode(struct node *node) {
    struct node* current = node;

    while(current && current->left != nullptr)
        current = current->left;

    return current;
}

struct node *deleteNode(struct node *root, int key) {
    std::cout << "\nDeleting [" << key << ']' << std::endl;
    if(root == nullptr) return root;


    if(key < root->key) {
        std::cout << "Going down left.. [" << key << " < " << root->key << "]" <<  std::endl;
        root->left = deleteNode(root->left, key);
    }
    else if(key > root->key) {
        std::cout << "Going down right.. [" << key << " > " << root->key << "]" <<  std::endl;
        root->right = deleteNode(root->right, key);
    }
    else {


        std::cout << "Is root->left null?" << std::endl;
        if(root->left == nullptr) {
            std::cout << "Yes, switch with root->right." << std::endl;
            struct node *temp = root->right;
            free(root);
            return temp;
        } else if(root->right == nullptr) {
            std::cout << "No, switch with root->left." << std::endl;
            struct node *temp = root->left;
            free(root);
            return temp;
        }

        std::cout << "Neither. Dig down most-right." << std::endl;

        struct node *temp = minValueNode(root->right);

        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);

    }

    return root;
}

void inorder(struct node* root) {
    if(root == nullptr) {
        // std::cout << "STIGNAH DO DUNO!!"<< std::endl;
        return;
    }

    // std::cout << "<---slizam nalqvo ot [" << root->key << "]" << std::endl;
    inorder(root->left);

    // std::cout << "PRINT: " << root->key << " \n";
    std::cout<< root->key << " ";
    // std::cout << "slizam naDQSNO ---> ot [" << root->key << "]" << std::endl;
    inorder(root->right);
    // std::cout << "[NQMA NISHTO, VRUSHTAM NAGORE] ot [" << root->key << "]" <<  std::endl;
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