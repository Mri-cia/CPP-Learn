#pragma once
#include <iostream>
#include <string>
#include <limits>

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

inline void waitForEnter() {
    logn("Press Enter to continue...");
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}

#endif