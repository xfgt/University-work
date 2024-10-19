//
// Created by Slave on / Saturday / 19-Oct-24.
//


#include <iostream>


unsigned int cnt{};

void probaRekursiq(int x){
  if(x == 0){
    std::cout << cnt << std::endl;
    return;
  }

  cnt++;
  probaRekursiq(--x);
}


void gcd(int a, int b){

  if(b == 0){
    cnt = a;
    return;
  } else {
    std::cout << " -> " << b;
    gcd(b, a%b);
    std::cout << " <- " << a;
    return;
  }
}



int main(){

  probaRekursiq(5);
  gcd(462, 82);
  std::cout <<  "\ngcd = " << cnt << std::endl;
  return 0;
}
