


#include <iostream>
#include <iomanip>
#include <chrono>
#include "LinkedList.h"

using namespace std::chrono;


const int size = 20;

int main() {

    std::setprecision(6);
    srand(time(NULL));

    // Създаване на обекти от тип единично свързан списък
    LinkedList list1, list2;

    // Запълване на 1-вия обект със случайни числа от 1 до 1000
    list1.fillRandom(size, 1, 1000);
    list2.copyFrom(list1); // Копиране на стойностите от първия обект във втория.

    // Първо принтиране двата списъка - показно за ориентир и сравнение дали списъка е сортиран в следващите редове.
    list1.print();
    list2.print();


    // Измернване на времето за сортиране на списъка чрез Merge sort алгоритъма.
    auto startMerge = std::chrono::high_resolution_clock::now();
    list1.sortWithMergeSort();
    auto endMerge = std::chrono::high_resolution_clock::now();
    duration<double, std::milli> mergeDuration = endMerge - startMerge;
    std::cout << "Mergesort time: " << mergeDuration.count() << " ms\n";


    // Измернване на времето за сортиране на списъка чрез Quick sort алгоритъма.
    auto startQuick = std::chrono::high_resolution_clock::now();
    list2.sortWithQuickSort();
    auto endQuick = std::chrono::high_resolution_clock::now();
    duration<double, std::milli> quickDuration = endQuick - startQuick;
    std::cout << "Quicksort time: " << quickDuration.count() << " ms\n";


    // Второ принтиране двата списъка - вече сортираните единични свързани списъци.
    list1.print();
    list2.print();
    return 0;
}
