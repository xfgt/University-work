//
// Created by twister on 8/26/24.
//

#include <iostream>
#include <iomanip>


int main(){
    using namespace std;


    int number;

    while(cin >> number){
        if(number % 2 == 0){
            cout << "The number is: " << abs(number) << endl;
        } else{
            cout << "Please write an even number." << endl;
        }
    }


    return 0;
}
