//
// Created by MRSLAVE on 10-Dec-24.
//
#include <iostream>
#include <string>
#include <sstream>


std::streambuf* CUSTOM_READ() {
    std::ostringstream local;
    auto cin_buff = std::cin.rdbuf(); // check _M_file -> _ptr && _base
    return cin_buff;
}

int main() {


//  basic input
    // char x, y;
    // std::cin >> x;
    // std::cin >> y;
    //
    // int de;
    // std::cin >> de;
    //
    // std::string asdf;
    // std::getline(std::cin, asdf);
    //  lR71hello

//  print each read character in ascii
    // char ch;
    // while(std::cin.get(ch)){
    //     printf("[%d]", ch);
    // }

//  stack read a word fixed size (we count the '\000')
    // const size_t sz = 3;
    // char e[sz+1];
    // std::cin.get(e, sz+1);



//  read the rest of a buffer
    char a[31];
    std::cin.get(a, 31);
    std::cout << a << std::endl;;

    auto f = stdin->_base;
    auto g = stdin->_bufsiz;
    auto l = stdin->_charbuf;
    auto y = stdin->_cnt;
    auto m = stdin->_file;
    auto t = stdin->_flag;
    auto x = stdin->_ptr;
    auto r = stdin->_tmpfname;

    std::cout << x;




    // std::cin.ignore();
    // std::cin.getline();
    // std::cin.sync();
    // std::cin.clear();
    // std::cin.tie();


    return 0;
}