#include <iostream>
#include <chrono>
#include "LinkedList.h"

/**
 * @brief Main function to test merge sort and quick sort with timing
 */
int main() {
    LinkedList list1, list2;
    const int size = 10000;

    list1.fillRandom(size);
    list2.copyFrom(list1);

    auto startMerge = std::chrono::high_resolution_clock::now();
    list1.sortMerge();
    auto endMerge = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> mergeDuration = endMerge - startMerge;
    std::cout << "Merge Sort took " << mergeDuration.count() << " ms\n";

    auto startQuick = std::chrono::high_resolution_clock::now();
    list2.sortQuick();
    auto endQuick = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> quickDuration = endQuick - startQuick;
    std::cout << "Quick Sort took " << quickDuration.count() << " ms\n";

    return 0;
}
