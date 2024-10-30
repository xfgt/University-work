//
// Created by Slave on / Saturday / 19-Oct-24.
//


#include <algorithm>
#include <iostream>
unsigned cnt;
unsigned result;

void probaRekursiq(int x){
  if(x == 0){
    std::cout << cnt << std::endl;
    return;
  }

  cnt++;
  probaRekursiq(--x);
}
void gcd(long long a, long long b, unsigned& cnt){
  ++cnt;
  // гмуркане '->'
  // изплуване '<-'
  if(b == 0){
    result = a;
    return;
  } else {
    std::cout << " -> " << b;
    gcd(b, a%b, cnt);
    std::cout << " <- " << a;
    return;
  }
}
long long fct(unsigned x) {
  long long out;
  if(x < 1) return 1;
  else {
    printf("DIVE:\\/\\/\\/\\/\\/\\/\n(out)\t[%x] -> %d\n(x)\t{%x} = %d\n\n", &x, x, &out, out);
    out = x * fct(x-1);
    printf("EMERGE:/\\/\\/\\/\\/\\/\\\n(out)\t[%x] -> %d\n(x)\t{%x} = %d\n\n", &x, x, &out, out);
  }

  return out;
}

void bubbleSort(int* a, unsigned n) {
  bool swapped;
  for(int i = 0; i < n-1; ++i) {
    swapped = 0;
    for(int j = 0; j < n-i-1; ++j) {
      if(a[j] > a[j+1]) {
        int temp = a[j];
        a[j] = a[j+1];
        a[j+1] = temp;
        swapped = 1;
      }
    }
    if(!swapped) break;
  }

}

int binarySearchRecursive(int* a, int low, int high, int search) {
  while(high >= low) {
    int mid = low + (high - low) / 2;
    if(a[mid] == search) return mid;
    if(a[mid] > search) return binarySearchRecursive(a, low, mid - 1, search);
    return binarySearchRecursive(a, mid + 1, high, search);
  }
  return -1;
}
int main(){

  long long xs = fct(16);



  srand(time(0));

  int sz = 100;
  int A[sz]{};

  for(int i = 0; i < sz; i++)
    A[i] = rand() % sz + 1;

  bubbleSort(A, sz); // make sure the array is sorted first.

  for(const auto& it : A) std::cout << it << ' ';
  std::cout << std::endl;

  auto lower = std::lower_bound(A, A+sz, 4);
  auto upper = std::upper_bound(A, A+sz, 82);
  auto l = std::lower_bound(A, A+sz, 80);
  auto eq = std::equal_range(A, A+sz, 80);

  std::cout << *lower << std::endl;
  std::cout << *upper << std::endl;
  std::cout << *l << std::endl;
  printf("equal_range(pair):\t [first: %d, second: %d]", *eq.first, *eq.second);


  int x{};
  std::cout << "\nEnter x:\t";
  std::cin >> x;

  int r =  binarySearchRecursive(A, 0, sz-1, x);
  printf("Do we have %d?\t[%s]", x, (r!=-1) ? "yes" : "no");

  return 0;
}
