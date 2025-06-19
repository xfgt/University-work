#include <iostream>

bool is_prime(int& n) {

    if (n == 1) {
        return false;
    }

    int i = 2;
    while (i*i <= n) {
        if (n % i == 0) {
            return false;
        }
        i += 1;
    }
    return true;
}

resd
void printBitmask(int* sample, const int& size){
    std::cout << '[' << ' ';
    for(int i = 0; i < size; i++){
        std::cout << sample[i] << ' ';
    }
    std::cout << ']' << std::endl;
}

bool isSubset(int* a, const int& asz, int* b, const int& bsz){

    // all of b are in a
    int max{};
    for(int i = 0; i < asz; i++){
        if(a[i] == 1)
            max++;
    }

    int count{};
    for(int i = 0; i < bsz; i++){
        if(b[i] == 1){
            for(int j = i; j < bsz; j++, i++){
                if(b[i] == 1 && a[j] == 1){
                    count++;
                    if(count == max)
                        return true;

                }
            }
        }

    }



    return false;
}


void fillBitmaskA(int* sample, const int& size){
    int n{};

    for(int i = 0; i < size; i++){
        sample[i] = 0;
    }
    std::cout << "give input A: \t";
    while(true){
        std::cin >> n;

        if(n >= 1 && n <= 10){
            sample[n] = 1;
        }
        if(std::cin.get() == '\n') break;

    }
}


void fillBitmaskB(int* sample, const int& size){
    int n{};

    for(int i = 0; i < size; i++){
        sample[i] = 0;
    }
    std::cout << "give input B: \t";
    while(true){
        std::cin >> n;

        if(is_prime(n)){
            sample[n] = 1;
        }
        if(std::cin.get() == '\n') break;

    }
}

void fillBitmaskC(int* sample, const int& size){
    int n{};

    for(int i = 0; i < size; i++){
        sample[i] = 0;
    }
    std::cout << "give input C:\t";
    while(true){
        std::cin >> n;

        if(n > 1 && n <= 6) {
            if(n % 2 == 1){
                sample[n] = 1;
            }
        }
        if(std::cin.get() == '\n') break;

    }
}




int main() {

    int bitmaskA[11];
    int bitmaskB[12];
    fillBitmaskA(bitmaskA, 11);
    fillBitmaskB(bitmaskB, 12);

    printBitmask(bitmaskA, 11);
    printBitmask(bitmaskB, 12);
    std::cout << std::boolalpha << "is subset: " << isSubset(bitmaskA, 11, bitmaskB, 12) << std::endl;


    int bitmaskC[7];
    int bitmaskD[3] = {0, 1, 1};
    fillBitmaskC(bitmaskC, 7);

    printBitmask(bitmaskC, 7);
    printBitmask(bitmaskD, 3);
    std::cout << std::boolalpha << "is subset: " << isSubset(bitmaskC, 7, bitmaskD, 3) << std::endl;


    int bitmaskE[1] = {1};
    printBitmask(bitmaskE, 1);




    return 0;
}