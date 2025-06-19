#include <iostream>

int getLowest(int* sx, const int& sz){
    int find = sx[0];
    for(int i = 0; i < sz; i++){
        if(find > sx[i])
            find = sx[i];
    }
    return find;
}

int getLargest(int* sx, const int& sz){
    int find = sx[0];
    for(int i = 0; i < sz; i++){
        if(find < sx[i])
            find = sx[i];
    }
    return find;
}




void solve(int* sa, const int& asz, int* sb, const int& bsz){
    int lowest = getLowest(sb, bsz);
    int largest = getLargest(sb, bsz);
    int sum{};

    for(int i = 0; i < asz; i++){
        if(sa[i] >= lowest && sa[i] <= largest){
            sum += sa[i];
            std::cout << sa[i] << " ";
        }
    }


    std::cout << std::endl << sum << std::endl;
};

int main(){

    int SetA[10] {5, 2, 3, 8, 1, 6, 4, 12, 9, 10};
    int SetB[3] {6, 9, 4};

    solve(SetA, 10, SetB, 3);


    return 0;
}