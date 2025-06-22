#pragma once
#include "string_util.hpp"
#include "data_user.hpp"


class User {
private:
    string username;
    string password;
    int balance = 0;
    
public:
    User();

    User(const string& username, const string& password);

    void deposit(const int& value);

    void withdraw(const int& value);

    bool operator==(const User& other);

    void printInfo();

    string getUsername(){
        return this->username;
    }

    string getPassword(){
        return this->password;
    }

};




