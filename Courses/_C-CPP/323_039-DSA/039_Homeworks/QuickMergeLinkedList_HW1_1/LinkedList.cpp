#include "LinkedList.h"


/**
 * @brief Дефиниция конструктора за Node
 * @param val Стойност за аргумент, която да се подава към конструктора.
 * @param data Копира стойността на val.
 * @param next Стойност по подразбиране - нулевия указател 0x0.
 **/
Node::Node(int val) : data(val), next(nullptr) {}

/**
 * @brief Дефиниция конструктора за LinkedList
 * @param head Стойност по подразбиране - нулевия указател 0x0.
 **/
LinkedList::LinkedList() : head(nullptr) {}

/**
 * @brief Дефиниция копиращ конструктор за LinkedList
 * @param other Константен указател от тип LinkedList по референция (чистия указател, без да се създават скрити копия)
 * @details
 * 1. Изчиства данните от конкретния (this) списък.
 * 2. Запазва началната точка на other.
 * 3. Обхожда списъка, започвайки от отправната точка other.
 * 4. Презаписва с данните копирани от подадения списък.
 **/
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

/**
 * @brief Дестуктора на типа.
 * @details Извиква clear()
 **/
LinkedList::~LinkedList() {
    clear();
}
/**
 * @brief Изчиства данните от списъка. Деалокира заделената динамична памет.
 * @details Извиква се в деструктора на типа.
 **/
void LinkedList::clear() {
    Node* curr = head;
    while (curr) {
        Node* next = curr->next;
        delete curr;
        curr = next;
    }
    head = nullptr;
}
/**
 * @brief Принтира списък.
 **/
void LinkedList::print() const {
    Node* temp = head;
    while (temp) {
        std::cout << temp->data << ' ';
        temp = temp->next;
    }
    std::cout << "\n";
}
/**
 * @brief Добавя елемент в списъка
 * @param data Стойността на елемента.
 **/
void LinkedList::push(int data) {
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}
/**
 * @brief Запълва писъка със случайни числа.
 * @param count Броя на тези числа (определя размера на списъка)
 * @param lower Долна граница (от)
 * @param lower Горна граница (до)
 * @details Използва rand().
 **/
void LinkedList::fillRandom(int count, int lower, int upper) {
    clear();
    for (int i = 0; i < count; ++i)
        push(rand() % upper + lower);
}

void LinkedList::sortWithMergeSort() {
    head = mergeSort(head);
}

void LinkedList::sortWithQuickSort() {
    head = quickSort(head);
}










/**
 *  @brief Дефиниция на алгоритъма Merge sort.
 *  @details
 *  1. Разделяме списъка на две части.
 *  2. Процедурата се изпълнява рекурсивно за всяка една част до пълно потъване.
 *  3. След достигане на два сортирани списъка се прилага процедура на обединение
 *  върху тях, а резултата от самата процедура е началото на вече наредения единично свързан списък!
 */
Node* LinkedList::mergeSort(Node* head) {
    if (!head || !head->next) return head;

    Node *a, *b;
    frontBackSplit(head, &a, &b);

    a = mergeSort(a);
    b = mergeSort(b);

    return merge(a, b);
}

/**
 *  @brief a.k.a "Split the front and back!!!"
 *  @cite Разделяй и владей!
 *  @ref Юлий Цезар
 *
 *  @param head Указател сочещ към корена на списъка.
 *  @param frontRef Указател сочещ началото на първия списък.
 *  @param backRef Указател сочещ началото на втория списък.
 *  @return Нищо. void е. Презаписва frontRef и backRef.
 */
void LinkedList::frontBackSplit(Node* head, Node** frontRef, Node** backRef) {
    Node* node_in_advance = head->next;
    Node* node_before = head;

    while (node_in_advance) {
        node_in_advance = node_in_advance->next;

        if (node_in_advance) {
            node_before = node_before->next;
            node_in_advance = node_in_advance->next;
        }


    }

    *frontRef = head;
    *backRef = node_before->next;
    node_before->next = nullptr;
}


/**
 * @brief Процедурата по обединение.
 * @param а Първия половин списък.
 * @param b Втория половин списък.
 * @return Указател към началото на обединените два списъка в един цял.
 */
Node* LinkedList::merge(Node* a, Node* b) {
    if (!a) return b;
    if (!b) return a;

    Node* result = nullptr;
    if (a->data <= b->data) {
        result = a;
        result->next = merge(a->next, b);
    } else {
        result = b;
        result->next = merge(a, b->next);
    }
    return result;
}















/**
 * @brief Функцията достъпваща се от обект от тип LinkedList водеща до реализацията на алгоритъма Quick sort
 * @details Пренасочва действието си към функция quickSortRecur(Node*, Node**, Node**);
 * @return Указател тип Node от функцията quickSortRecur(Node*, Node**, Node**), сочещ началото на списъка.
 */
Node* LinkedList::quickSort(Node* head) {
    Node *newHead = nullptr, *newEnd = nullptr;
    return quickSortRecur(head, &newHead, &newEnd);
}
/**
 *
 * @brief Реализацията на Quick sort.
 * @param head началото на списъка
 * @param newHead Новото началото на списъка след извършване на сортирането.
 * @param newEnd Новият край на списъка след извършване на сортирането.
 * @details
 * 1. В началото се извършва условна проверна на това дали подадения указател към началото и неговия следващ
 * са валидни. Ако не са, се пренасочват новите начало и край, към това което всъщност сочи.
 *
 * 2. Ако проверката не се осъществи и имаме подаден валиден указател,
 * то се продължава към избирането на ос (pivot), която е всъщност корена на списъка.
 *
 * 3. Избира се следващия елемент на оста, с който след това се обхожда целия списък,
 * сравнявайки се стойностите на конкретния елемент с неговия следващ.
 *
 * 4. Пренареждат се при неспазена наредба, указана във вписаното условие на зависимост,
 * след което се продължава към следващия елемент от списъка.
 *
 * 5. Процедурата се изпълнява рекурсивно, за да се извадят указателите сочещи началото на списъците съответно
 * наредените стойности по-малки от оста и по-големи от оста.
 *
 * 6. Обединяват се и се извежда указателя сочещ началото на вече наредения списък.
 *
 * @return Указател тип Node, сочещ началото на списъка.
 */
Node* LinkedList::quickSortRecur(Node* head, Node** newHead, Node** newEnd) {

    if (!head || !head->next) {
        *newHead = head;
        *newEnd = head;
        return head;
    }


    Node* pivot = head;
    Node *smallerValueNode = nullptr, *largerValueNode = nullptr;
    Node *smallTail = nullptr, *bigTail = nullptr;

    Node* currentNode = head->next;
    pivot->next = nullptr;

    while (currentNode) {
        Node* next = currentNode->next;
        currentNode->next = nullptr;
        if (currentNode->data < pivot->data) {
            if (!smallerValueNode) smallerValueNode = smallTail = currentNode;
            else smallTail->next = currentNode, smallTail = currentNode;
        } else {
            if (!largerValueNode) largerValueNode = bigTail = currentNode;
            else bigTail->next = currentNode, bigTail = currentNode;
        }
        currentNode = next;
    }

    Node* sortedLess = quickSort(smallerValueNode);
    Node* sortedGreater = quickSort(largerValueNode);

    *newHead = sortedLess ? sortedLess : pivot;

    if (sortedLess) {
        Node* temp = sortedLess;
        while (temp->next) temp = temp->next;
        temp->next = pivot;
    }
    pivot->next = sortedGreater;

    *newEnd = sortedGreater ? bigTail : pivot;

    return *newHead;
}