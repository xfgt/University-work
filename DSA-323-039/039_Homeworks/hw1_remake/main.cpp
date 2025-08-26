
// main.cpp
// Компилатор: MSVC
// Версия C++ 14
// Работа на Теодор Мангъров
// факултетен номер: F113621



#include <iostream>
#include <list>
#include <cstdlib> // random
#include <chrono> // time



using STL_LinkedList = std::list<int>;



STL_LinkedList merge(const STL_LinkedList& firstObj, const STL_LinkedList& secondObj) {
    STL_LinkedList result;

    auto ptr_first = firstObj.begin(), ptr_second = secondObj.begin();

    while (ptr_first != firstObj.end() && ptr_second != secondObj.end()) {

        (*ptr_first <= *ptr_second) ?

            result.push_back(*ptr_first++)      :    result.push_back(*ptr_second++);
        
    }
    

    result.insert(result.end(), ptr_first, firstObj.end());
    result.insert(result.end(), ptr_second, secondObj.end());
   

    return result;
}


STL_LinkedList mergeSort(STL_LinkedList obj) {
    if (obj.size() <= 1)
        return obj;

    auto mid = obj.begin();
    std::advance(mid, obj.size() / 2); // move the pointer to the middle

    STL_LinkedList left(obj.begin(), mid);
    STL_LinkedList right(mid, obj.end());

    return merge(mergeSort(left), mergeSort(right));
}



STL_LinkedList quickSort(STL_LinkedList obj) {
    if (obj.size() <= 1)
        return obj;

    auto pivot = obj.begin();
    int pivotVal = *pivot;
    obj.erase(pivot); 

    STL_LinkedList less, greater;

    for (int val : obj) {
        if (val < pivotVal)
            less.push_back(val);
        else
            greater.push_back(val);
    }

    less = quickSort(less);
    greater = quickSort(greater);

    less.push_back(pivotVal);            
    less.splice(less.end(), greater);    

    return less;
}


inline int getRand(int low, int high) {
    return low + rand() % (high - low + 1);
}

STL_LinkedList makeRandomList(int numberOfElements, int low, int high) {
    STL_LinkedList sample;
    for (int i = 0; i < numberOfElements; i++) {
        sample.push_back(getRand(low, high));
    }
    return sample;
}

inline void printList(const char* title, const STL_LinkedList& obj) {
    std::cout << title;
    for (int x : obj)
        std::cout << x << ' ';  
    std::cout << '\n';
}


void perform(int numberOfElements, int low, int high) {

    std::cout << "numberOfElements: " << numberOfElements << '\n';



    STL_LinkedList lst = makeRandomList(numberOfElements, low, high);
//  printList("randomValues: ", lst);
//  std::cout << '\n';


    //time
    auto start = std::chrono::steady_clock::now();
    STL_LinkedList sortedMerge = mergeSort(lst);
    auto end = std::chrono::steady_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    //printList("Merge sort: ", sortedMerge);
    std::cout << "Duration mergeSort: " << duration << " ms.\n";

    

    //time
    start = std::chrono::steady_clock::now();
    STL_LinkedList sortedQuick = quickSort(lst);
    end = std::chrono::steady_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    //printList("Quick sort: ", sortedQuick);
    std::cout << "Duration quickSort: " << duration << " ms.\n";
    std::cout << '\n';
}


int main() {

    srand(time(NULL));

    
    for (int i = 10; i < 100000; i *= 3) {
            perform(i, 0, 100);
            //system("pause");
    }
   
    
    

    return 0;
}
