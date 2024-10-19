#include <iostream>


void swap(int& a, int& b){
    int temp = a;
    a = b;
    b = a;
}


void knownSize(int* a, int& n) {
    int c{};

    for (int i = 1; i < n - 1; i++) {
        for (int j = 0; j < n - 2; j++) {
            c++;
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
            }

        }
    }
    std::cout << c << std::endl;
}


void betterVersion(int* a, int& n){
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

    std::cout << c <<  std::endl;

}

int main(){

    int a[] {2, 7, 4 , 1, 5 , 3};
    int n  = sizeof a / sizeof a[0];

    //knownSize(a, n);

    betterVersion(a, n);

    for(const auto& x : a)
        std::cout << x << ' ';



    return 0;
}