//
// Created by ADMIN on 05-Oct-25.
//

#include <iostream>
using namespace std;

class Base1{
    int b1;
public:
    Base1(int b1=1):b1(b1){cout<<"Base1 initialzed with "<<b1<<endl;}
    friend ostream& operator<<(ostream& os, const Base1 & ob);
};

class Base2{
    int b2;
public:
    Base2(int b2=2):b2(b2){cout<<"Base2 initialzed with "<<b2<<endl;}
    friend ostream& operator<<(ostream& os, const Base2 & ob);
};


class Deriv1:public Base1{
    int d1;
public:
    Deriv1(int b, int d):Base1(b),d1(d){
        cout<<"Deriv1 initialzed with "<<d1<<endl;
    }
    friend ostream& operator<<(ostream& os, const Deriv1 & ob);
};


class Deriv2:public Base1,public Base2{
    int d2;
public:
    Deriv2(int b, int b2, int d):Base1(b),Base2(b2),d2(d){
        cout<<"Deriv2 initialzed with "<<d2<<endl;
    }
    friend ostream& operator<<(ostream& os, const Deriv2 & ob);
};

ostream& operator<<(ostream& os, const Base1 & ob){return os<<" #b1="<<ob.b1;}
ostream& operator<<(ostream& os, const Base2 & ob){return os<<" #b2="<<ob.b2;}
ostream& operator<<(ostream& os, const Deriv1 & ob){return os<<(Base1)ob<<" #d1="<<ob.d1;}
ostream& operator<<(ostream& os, const Deriv2 & ob){return os<<(Base1)ob<<(Base2)ob<<" #d2="<<ob.d2;}


int main(){


    // example 8
#if 0
    Base1 b;
    cout<<"Base1 object "<<b<<endl;
    cout<<"Size of Base1 object "<<sizeof(b)<<endl<<endl; // 4


    Base2 bb;
    cout<<"Base2 object "<<bb<<endl;
    cout<<"Size of Base2 object "<<sizeof(bb)<<endl<<endl; // 4




    Deriv1 d(11,22);
    cout<<"Deriv1 object "<<d<<endl;
    cout<<"Size of Deriv1 object "<<sizeof(d)<<endl<<endl; // 8


    Deriv2 dd(10,20,30);
    cout<<"Deriv2 object "<<dd<<endl;
    cout<<"Size of Deriv2 object "<<sizeof(dd)<<endl<<endl; // 12


    cout<<"Static upcast of Deriv2 to Base1:\n";
    b=dd;
    cout<<"Base1 object contains "<<b<<endl<<endl;


    cout<<"Static upcast of Deriv2 to Base2:\n";
    bb=dd;
    cout<<"Base2 object contains "<<bb<<endl;

#endif


    // IMPORTANT EXAMPLE 11 (using pointers for keeping all information during casting)
#if 1
    Base1 * bp = new Base1;
    cout<<"Base1 object "<<*bp<<endl;



    Deriv2 dd(10,20,30);
    cout<<"Deriv2 object "<<dd<<endl<<endl;

///     UPCASTING PROCEDURE
    cout<<"Static upcast of Deriv2 to Base1:\n";
    bp=&dd; // put a breakpoint in debugging
    cout<<"Base1 object part is "<<*bp<<endl; //#b1=10







///     DOWNCASTING PROCEDURE
    cout<<"Static downcast from Base1 to Deriv2:\n";

    //Deriv2 *dp = (Deriv2 *)bp;                    // c-style cast [original example]
    Deriv2 *dp = reinterpret_cast<Deriv2*>(bp);     // cpp version
    //                                     |
    //                                     |
    //                                     ^ ---- Do not put '&', gives WRONG values.

    /*
     * Explanation:
     *
     * We get the "cut(ed)" object from the previous procedure of upcasting to Base1,
     * and we restore the data back. We access it trough 'dp' pointer
     *
     */
    cout<<"The complete object is "<<*dp<<endl<<endl; // 10, 20, 30









    cout<<"Static upcast of Deriv2 to Base2:\n";
    Base2 *bb=&dd;
    cout<<"Base2 object object part is "<<*bb<<endl; // 20









    cout<<"Static downcast from Base2 to Deriv2:\n";
    dp = (Deriv2 *)bb;  // again, c-style casting from the original example.
    cout<<"The complete object is "<<*dp<<endl<<endl; // 10, 20, 30

#endif

    return 0;
}
