#include "algorithms.h"
void bubbleSort(int* a, int& n){
    int c{};
    bool flag = false;

    for(int i = 1; i < n - 1; i++){
        flag = false;
        for(int j = 0 ; j < n - i - 1; j++ ){
            c++;
            if(a[j] > a[j+1]){
                swap(a[j], a[j+1]);
                flag = true;
            }

        }
        if(!flag) break;
    }
}
