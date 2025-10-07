//
// Created by ADMIN on 07-Oct-25.
//

#include <string>
#include <iostream>
using namespace std;
int main( ) {
    try {
        string str( "VM" );
        string rstr( "ware" );
        str.append( rstr, 5, 3 );
        // VMware -         0       4
        cout << str << endl;
    }
    catch ( exception &e ) {
        cerr << "Caught: " << e.what( ) << endl;
        cerr << "Type: " << typeid( e ).name( ) << endl;
    };
}