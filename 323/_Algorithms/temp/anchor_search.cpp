#include <iostream>

using namespace std;

int main() {
  int a[6] = { 1, 2, 5, 7, 8 };
  int x;
  cin >> x;
  a[5] = x;
  bool found = false;
  int index = 0;

  while (a[index] != x)
    index++;

  if (index == 5)
    cout << "x ne e nameren";
  else  
    cout << "x e nameren";

  return 0;
}