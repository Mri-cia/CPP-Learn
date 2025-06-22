#include "data_user.hpp"
#include "user.hpp"  // include the full definition here

vector<User> DataUser::users;

void DataUser::initData() {
    users.emplace_back("Yaka", "iasfh39");
    users.emplace_back("Tula", "iasfh39");
    users.emplace_back("Ali", "iasfh39");
}

bool DataUser::verifyUser(User& user) {
    for (const User& u : users) {
        if (user == u) {
            return true;
        }
    }
    return false;
}

bool DataUser::containUser(string& user) {
    for (User& u : users) {
        if (user == u.getUsername()) {
            return true;
        }
    }
    return false;
}

User& DataUser::getUser(string& user) {
    for (User& u : users) {
        if (user == u.getUsername()) {
            return u;
        }
    }
    throw std::runtime_error("User not found");  // handle error
}

vector<User> DataUser::getUsers(){
    return users;
}

void DataUser::transferIn(User& activeUser, User& targetUser, const int& value){
    for(User& u : users){
        if (targetUser == u){
            u.deposit(value);
            activeUser.withdraw(value);
            return;
    }
    }
    log("[Error] There are no target user.");
}

