#include <iostream>

void solve(char* a, int* bitmask, const int& sz, int& k, char* sample, int& size){
    int count{};
    int g{};
    for(int i = sz; i >= 0; i--){

        if(a[i] >= 'A' && a[i] <= 'Z'){
            if(count >= k){
                size = g;
                break;
            }
            if(bitmask[i] == 1){
                count++;
                sample[g] = a[i];
                g++;
            }

        }
    }
}


int main(){


    int k;
    std::cin >> k;

    char letters[10] { 'e', 'r', 'D', 'U', 'w', 'm', 'B', 'x', 'N', 'z' };
    int A[10]{ 1, 0, 1, 1, 1, 0, 1, 0, 1, 1 };
    char sample[10];
    int size{};
    solve(letters, A, 10, k, sample, size);


    for(int i = 0; i < size; i++){
        std::cout << sample[i];
    }

    return 0;
}