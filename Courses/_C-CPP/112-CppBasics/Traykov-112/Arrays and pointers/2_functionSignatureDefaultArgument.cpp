#include <iostream>
using namespace std;
int ff(int a, int b, int c =0);
int ff(int a, int b=0, int c);
int ff(int a=0, int b, int c);
int main()
{

    cout << ff() << endl;
    cout << ff(1) << endl;
    cout << ff(1,2) << endl;
    cout << ff(1,2,3) << endl;
}
int ff(int a, int b, int c){
    return a+b+c;
}