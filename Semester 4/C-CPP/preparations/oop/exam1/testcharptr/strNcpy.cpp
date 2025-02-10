// Example program
#include <iostream>
#include <string.h>

int main()
{
  char x[] = " asdf";
  char y[] = "";
  
  std::cin >> y;
  
  
  std::cout << x << std::endl;
  std::cout << y << std::endl;
  
  strncpy(x, y, 5);
  
  std::cout << x << std::endl;
  std::cout << y << std::endl;
  
  
  
}
