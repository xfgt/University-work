#include "LinkedList.h"
#include <cstdlib>

Node::Node(int val) : data(val), next(nullptr) {}

LinkedList::LinkedList() : head(nullptr) {}

LinkedList::~LinkedList() {
    clear();
}

void LinkedList::push(int data) {
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

void LinkedList::print() const {
    Node* temp = head;
    while (temp) {
        std::cout << temp->data << ' ';
        temp = temp->next;
    }
    std::cout << "\n";
}

void LinkedList::clear() {
    Node* curr = head;
    while (curr) {
        Node* next = curr->next;
        delete curr;
        curr = next;
    }
    head = nullptr;
}

void LinkedList::fillRandom(int count) {
    clear();
    for (int i = 0; i < count; ++i)
        push(rand() % 1000);
}

void LinkedList::copyFrom(const LinkedList& other) {
    clear();
    Node* temp = other.head;
    Node* prev = nullptr;
    while (temp) {
        Node* newNode = new Node(temp->data);
        if (!head) head = newNode;
        else prev->next = newNode;
        prev = newNode;
        temp = temp->next;
    }
}

void LinkedList::sortMerge() {
    head = mergeSort(head);
}

void LinkedList::sortQuick() {
    head = quickSort(head);
}

// ----------- Merge Sort Implementation -----------

Node* LinkedList::mergeSort(Node* h) {
    if (!h || !h->next) return h;

    Node *a, *b;
    frontBackSplit(h, &a, &b);

    a = mergeSort(a);
    b = mergeSort(b);

    return sortedMerge(a, b);
}

Node* LinkedList::sortedMerge(Node* a, Node* b) {
    if (!a) return b;
    if (!b) return a;

    Node* result = nullptr;
    if (a->data <= b->data) {
        result = a;
        result->next = sortedMerge(a->next, b);
    } else {
        result = b;
        result->next = sortedMerge(a, b->next);
    }
    return result;
}

void LinkedList::frontBackSplit(Node* source, Node** frontRef, Node** backRef) {
    Node* fast = source->next;
    Node* slow = source;

    while (fast) {
        fast = fast->next;
        if (fast) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *frontRef = source;
    *backRef = slow->next;
    slow->next = nullptr;
}

// ----------- Quick Sort Implementation -----------

Node* LinkedList::quickSort(Node* head) {
    Node *newHead = nullptr, *newEnd = nullptr;
    return quickSortRecur(head, &newHead, &newEnd);
}

Node* LinkedList::quickSortRecur(Node* head, Node** newHead, Node** newEnd) {
    if (!head || !head->next) {
        *newHead = head;
        *newEnd = head;
        return head;
    }

    Node* pivot = head;
    Node *lessHead = nullptr, *greaterHead = nullptr;
    Node *lessTail = nullptr, *greaterTail = nullptr;
    Node* cur = head->next;
    pivot->next = nullptr;

    while (cur) {
        Node* next = cur->next;
        cur->next = nullptr;
        if (cur->data < pivot->data) {
            if (!lessHead) lessHead = lessTail = cur;
            else lessTail->next = cur, lessTail = cur;
        } else {
            if (!greaterHead) greaterHead = greaterTail = cur;
            else greaterTail->next = cur, greaterTail = cur;
        }
        cur = next;
    }

    Node* sortedLess = quickSort(lessHead);
    Node* sortedGreater = quickSort(greaterHead);

    *newHead = sortedLess ? sortedLess : pivot;
    if (sortedLess) {
        Node* temp = sortedLess;
        while (temp->next) temp = temp->next;
        temp->next = pivot;
    }
    pivot->next = sortedGreater;

    *newEnd = sortedGreater ? greaterTail : pivot;
    return *newHead;
}
