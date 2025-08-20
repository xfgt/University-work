#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

/**
 * @brief Node structure for singly linked list
 */
struct Node {
    int data;       ///< Data stored in the node
    Node* next;     ///< Pointer to the next node

    /**
     * @brief Constructor
     * @param val Initial value for node
     */
    Node(int val);
};

/**
 * @brief Singly Linked List class with sorting functionalities
 */
class LinkedList {
private:
    Node* head;

    // Merge sort helpers
    Node* mergeSort(Node* head);
    Node* sortedMerge(Node* a, Node* b);
    void frontBackSplit(Node* source, Node** frontRef, Node** backRef);

    // Quick sort helpers
    Node* quickSort(Node* head);
    Node* quickSortRecur(Node* head, Node** newHead, Node** newEnd);
    Node* partition(Node* head, Node* end, Node** newHead, Node** newEnd);

public:
    /**
     * @brief Constructor
     */
    LinkedList();

    /**
     * @brief Destructor
     */
    ~LinkedList();

    /**
     * @brief Insert new element at head
     * @param data Value to insert
     */
    void push(int data);

    /**
     * @brief Print list
     */
    void print() const;

    /**
     * @brief Clear the entire list
     */
    void clear();

    /**
     * @brief Fills the list with random integers
     * @param count Number of elements to generate
     */
    void fillRandom(int count);

    /**
     * @brief Sorts the list using Merge Sort
     */
    void sortMerge();

    /**
     * @brief Sorts the list using Quick Sort
     */
    void sortQuick();

    /**
     * @brief Deep copy the list from another instance
     * @param other List to copy from
     */
    void copyFrom(const LinkedList& other);
};

#endif // LINKEDLIST_H
