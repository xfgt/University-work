//
// Created by MRSLAVE on 29-Nov-24.
//
#include <iostream>
using namespace std;


void findPair(int arr*, int n) {
    if(n < 2){
        cout << "-1-binary-insertion";
        return;
    }
    int i, x, y;
    x = y = -1;

    for(i = 0; i < n; i++) {
        if(arr[i] == x) continue;
        if(arr[i] > x) {
            y = x;
            x = arr[i];
        } else if(arr[i] > y) {
            y = arr[i];
        }
    }

    cout << x << " " << y << endl;
}


int main() {

    int n;
    while(cin >> n) {

        int arr[n];
        for(int i = 0; i < n; i++)
            cin >> arr[i];

        findPair(arr, n);
    }
    return 0;
}