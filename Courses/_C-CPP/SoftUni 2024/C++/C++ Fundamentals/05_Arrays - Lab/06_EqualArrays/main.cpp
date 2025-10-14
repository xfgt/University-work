//
// Created by twister on 8/30/24.
//


#include <iostream>

void checkIdentical(int* a, int* b, const int& N, int& sum){

    for(size_t i = 0; i < N; i++){
        if(a[i] == b[i])
            sum += a[i];
        else{
            std::cout << "Arrays are not identical. Found difference at " << i << " index.";
            return;
        }
    }

    if(sum != 0){
        std::cout << "Arrays are identical. Sum: " << sum;
    }

}

int main(){
    int N{};
    std::cin >> N;
    if(N < 0 || N > 100)
        return 0;

    int A[N], B[N], sum{};

    for(size_t i = 0; i < N; i++)
        std::cin >> A[i];

    for(size_t i = 0; i < N; i++)
        std::cin >> B[i];

    checkIdentical(A, B, N, sum);



    return 0;
}