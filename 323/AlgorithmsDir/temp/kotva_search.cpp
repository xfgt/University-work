#include <iostream>




int main (){

    int a[] {2, 7, 4 , 1, 5 , 3};
    int n  = sizeof a / sizeof a[0];
    n++;
    int x;
    std::cin >> x;
    a[n] = x;
    for(int i = 0 ; i < n; i++){
        if(a[i] == x){
            std::cout << "ima go";
            break;
        }
    }





    return 0;
}