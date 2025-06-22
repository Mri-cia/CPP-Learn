#include "user.hpp"

User::User() 
    :username(""), password("")
{}

User::User(const string& username, const string& password)
        : username(username), password(password)
    {};

void User::deposit(const int& value){
        this->balance += value;
}

void User::withdraw(const int& value){
        this->balance -= value; 
}

bool User::operator==(const User& other){
    return this->username == other.username &&
        this->password == other.password;
}

void User::printInfo(){
    logn("---------- Balance ----------");
    log("Account Balance: "); logn(balance);
    logn("----------=========----------");
}