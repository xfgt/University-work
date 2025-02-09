//
// Created by MRSLAVE on 30-Jan-25.
//

#include <bits\stdc++.h>

int main() {

    int r{}, x{};
    int n{};
    while(std::cin >> n){
        if(n < 2 || n > 1000) return -1;

        while(n--) {
            int a, b;
            std::cin >> a >> b;
            if (a < 0 || b > 1000) return -1;
            r -= a;
            r += b;
            if(r > x)
                x = r;
        }

        std::cout << x << '\n';
    }

    return 0;
}