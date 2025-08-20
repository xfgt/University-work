#include <bits/stdc++.h>


void swap(int& i, int& j){
    int temp = i;
    i = j;
    j = temp;
}

void printArr(int* a, int& n){
    for(int i = 0 ; i < n; i++){
        std::cout << a[i];
    }
    std::cout << std::endl;
}


void permute(int* a, int size, int& n){
    if(size == 1){
        printArr(a, n);
        return;
    }


    for(int i = 0; i < size; i++){
        permute(a, size-1, n);
        if(size % 2 == 1)
            swap(a[0], a[size-1]);
        else
            swap(a[i],a[size-1]);

    }



}


int main(){


    int a[3] {1, 2, 3};
    int size = sizeof a / sizeof a[0];

    permute(a, size, size);


    return 0;
}