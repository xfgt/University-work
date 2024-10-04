#include <iostream>
#include <cstdlib>
#include <time.h>
#include <chrono>
using namespace std::chrono;


void doSwap(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}

void doPrint(int* a, const size_t sz){
    for(size_t i = 0; i < sz; i++)
        std::cout << a[i] << ' ';
    std::cout << std::endl;
}


void selectionSort(int* a, const size_t sz){
    //std::cout << "Selection sort" << std::endl;
    for(size_t i = 0; i < sz-1; i++){
            int emin = i;
        for(size_t j = i+1; j < sz; j++){
            //findmin
            if(a[j] < a[emin])
                emin = j;
        }
        //swap
        if(emin != i)
            doSwap(a[i], a[emin]);
    }

}


void bubbleSort(int* a, const size_t sz){
    bool flag = 0;
    for(size_t k = 1; k < sz-1; k++){
        flag = 0;

        for(size_t i = 0; i < sz-k-1; i++){
            if(a[i] > a[i+1]){
                doSwap(a[i], a[i+1]);
                flag = 1;
            }

        }
        if(flag == 0)
            break;

    }
}


void insertionSort(int* a, const size_t sz){ // FIX
    int temp{}, hole{};
    for(size_t i = 1; i < sz -1; i++){
        temp = a[i];
        hole = i-1;

        while(hole>=0 && a[hole] > temp){

            a[hole+1] = a[hole];
            hole = hole-1;
        }
        a[hole] = temp;
    }
}


int main()
{
for(size_t x = 10000; x <= 100000; x+=10000){


    srand(time(NULL));
    int iscr{};

    int sz = x;
    int A[sz];

    for(size_t i = 0; i < sz; i++) A[i] = rand() % sz + 1;

    //doPrint(A, sz);

    // time1
    auto start = high_resolution_clock::now();


    //selectionSort(A, sz);
    //bubbleSort(A, sz);

    insertionSort(A, sz);



    auto stop = high_resolution_clock::now();
    //time2


    auto dur = duration_cast<milliseconds>(stop - start);
   // std::cout << "TIME MEASURED: " << dur.count() << "ms. " << std::endl << std::endl;
    std::cout << dur.count() << std::endl;


    //doPrint(A, sz);


}
    return 0;
}
