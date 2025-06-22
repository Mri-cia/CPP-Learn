#pragma once
#include <iostream>
#include <string>

#ifndef STRING_UTIL_H
#define STRING_UTIL_H

using std::string;
using std::endl;

inline void log(const string& msg){
    std::cout << msg;
}

inline void log(const int& msg){
    std::cout << msg;
}

inline void logn(const string& msg){
    std::cout << msg << endl;
}

inline void logn(const int& msg){
    std::cout << msg << endl;
}


#endif