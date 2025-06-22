#pragma once
#include <vector>
#include <string>

using std::vector;
using std::string;

class User;

class DataUser{
// private:
//     DataUser();
private:
    static vector<User> users;
public: 
    static void initData();

    static bool verifyUser(User& user);

    static bool containUser(string& user);

    static User& getUser(string& user);

    static vector<User> getUsers();
    
    static void transferIn(User& activeUser, User& targetUser, const int& value);

};