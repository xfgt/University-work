//
// Created by twister on 8/26/24.
//

#include <iostream>


int main(){
    using namespace std;

    int odds{};
    int sum{};

    cin >> odds;

    int x{1};
    for(int i = 0; i < odds; i++){
        cout << x << endl;
        sum += x;
        x+=2;
    }

    cout << "Sum: " << sum << endl;
    return 0;
}