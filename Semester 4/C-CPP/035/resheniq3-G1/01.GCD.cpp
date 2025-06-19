#include <iostream>



bool hasPrimes(int* x, int sz){
    for(int i = 0; i < sz; i ++){
        if(x[i] % 2 == 0)

            return true;
    }
    return false;
}

int getLowest(int* x, int sz){
    int value = x[0];
    int i = 0;

    if(hasPrimes(x, sz)){
        while(i < sz){
            if(i % 2 == 0){
                if(value > x[i]){
                    value = x[i];
                }
            }
            i++;
        }
        return value;
    } else {
        while(i < sz){
            if(value > x[i]){
                value = x[i];
            }
            i++;
        }
        return value;
    }

}


int getLargest(int* x, int sz){
    int value = x[0];
    int i = 0;

    if(!hasPrimes(x, sz)){
        while(i < sz){
            if(i % 2 == 1){
                if(value < x[i]){
                    value = x[i];
                }
            }
            i++;
        }
        return value;
    } else {
        while(i < sz){
            if(value < x[i]){
                value = x[i];
            }
            i++;
        }
        return value;
    }

}

bool isInSecond(int x, int* a, int sza){
   for(int i = 0; i < sza; i++){
       if(x == a[i])
           return true;
   }
    return false;
}



int GCD(int* x, int sz){




    int a = getLowest(x, sz);
    int b = getLargest(x, sz);

    int result = std::min(a, b);
    while (result > 0) {
        if (a % result == 0 && b % result == 0) {
            break;
        }
        result--;
    }

    // Return gcd of a and b
    return result;
}



int main(){
    int a[5]{6, 11, 8, 7, 15};
    int b[10]{15, 2, 3, 8, 11, 6, 4, 12, 9, 10};

    int cross[15]{};
    int k{};
    for(int i = 0; i < 5; i++){
        if(isInSecond(a[i], b, 10)){
            cross[k] = a[i];
            k++;
        }
    }

    int i{};
    std::cout << "cross" << std::endl;
    
    for(; i < k; i++)
        std::cout << cross[i] << std::endl;

    std::cout << std::endl;
    std::cout << GCD(cross, i);
    return 0;
}