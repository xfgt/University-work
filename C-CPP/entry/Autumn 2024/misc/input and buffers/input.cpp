//
// Created by MRSLAVE on 10-Dec-24.
//
#include <iostream>
#include <string>
#include <sstream>


std::streambuf* CUSTOM_READ() {
    std::ostringstream local;
    auto cin_buff = std::cin.rdbuf(); // check _M_file -> _ptr && _base (STDIN FUNCTIONS)
    return cin_buff;
}

int main() {


//  basic input
     char x, y;
     std::cin >> x;
     std::cin >> y;

     int de;
     std::cin >> de;

     std::string asdf;
     std::getline(std::cin, asdf);
     //  test input: lR71hello

//  print each read character in ascii
     char ch;
     std::cout << "enter \'x\' to end." << std::endl;
     while(std::cin.get(ch)){
         if(ch == 'x') break;
         printf("[%d]", ch);
     }

//  stack read a word fixed size (we count the '\000')
    const size_t sz = 3;
    char e[sz+1];
    std::cin.get(e, sz+1);


//  read the rest of a buffer
    char a[31];
    std::cin.get(a, 31);
    std::cout << a << std::endl;;

    auto f = stdin->_base; // the whole buffer
    auto g = stdin->_bufsiz; // the buffer size in bytes
    auto l = stdin->_charbuf; //int
    auto gs = stdin->_cnt; // size of the rest of the buffer
    auto m = stdin->_file; //is it file?
    auto t = stdin->_flag; //int
    auto h = stdin->_ptr; // pointer to the const char* of the rest of the buffer
    auto r = stdin->_tmpfname; //null

    std::cout << x;


// ignore, get - unget

    char in[11];
    std::cin.get(in, 11);
    auto p = std::cin.rdbuf();
    std::cin.unget();
    std::cin.get();
    std::cin.ignore();
    std::cin.ignore();
    std::cin.get();
    std::cin.unget();
    std::cin.clear();
    std::cin.get();


//   untested
    std::cin.clear();
    std::cin.tie();
    system("@echo off");

    char qw = 7;
    while(1)
        std::cout << qw << std::flush;



    return 0;
}