//
// Created by twister on 8/26/24.
//

#include <iostream>


int main(){
    using namespace std;
    string country;
    getline(cin, country);


    if(country == "USA" || country == "England"){
        cout << "English";
    } else if( country == "Spain" || country == "Argentina" || country == "Mexico"){
        cout << "Spanish";
    } else{
        cout << "unknown";
    }

    return 0;
}