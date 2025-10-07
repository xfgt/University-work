//
// Created by ADMIN on 07-Oct-25.
//

#include <iostream>

int main() {

    // the type must match
    try {
        throw "EMERGENCY ERROR OF CONST CHAR XDDXXD";   // this may look like a std::string, but in c/c++ it is basic type named "const char*"

    } catch (std::string err) {                         // this won't catch
        std::cerr << "err" << '\n';


    } catch (const char*& ch_err) {                     // catch a type of [const char*] by reference (because of slicing)
        std::cerr << "Const char* error caught! :)\n" <<
            "Error: \"" << ch_err << "\"\n";

    }






    return 0;
}