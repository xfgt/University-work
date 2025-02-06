//
// Created by MRSLAVE on 29-Nov-24.
//

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;


int FL(int* a, int n) {
    int largest = a[0];
    int li = 0;

    for (int i = 1; i < n; i++) {
        if(a[i] > largest) {
            largest = a[i];
            li = i;
        }
    }
    a[li] = 0; // !
    return li;
}



int main() {
    int n, m;
    while(cin >> n >> m) {
        if(!(n <= 200 && m >= 1)) return -1;

        int a[n], c[n];
        for(int i = 0; i < n; ++i) cin >> a[i];
        memcpy(c, a, n * sizeof(int)); //a to c

        int bs[m]{};
        for(int i = 0; i < m; ++i) {
            bs[i] = FL(a, n);
        }

        sort(bs, bs+m);
        for(int i = 0; i < m; ++i) {
            cout << c[bs[i]] << ' ';
        }
        cout << endl;
    }


}