//
// Created by twister on 8/26/24.
//

#include <iostream>


int main(){
    using namespace std;

    double input{};

    cin >> input;


    if(input >= 3){
        cout << "Passed!" << endl;
    } else{
        cout << "Failed!" << endl;
    }

    return 0;
}