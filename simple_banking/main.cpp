#include "string_util.hpp"
#include "user.hpp"
#include <memory>

class DataUser;
void loginMenu();
void userMenu();

int main() {
    DataUser::initData();

    int indexApp = 1;

    while(indexApp != 0){
        loginMenu();
        log("Choose: ");
        int loginChoose;
        std::cin >> loginChoose;
        
        switch (loginChoose){
        case 1: {
            std::string name;
            std::string password;

            log("> Name: ");
            std::cin >> name;
            log("> Password: ");
            std::cin >> password;

            User tempUser(name, password);
            int indexUserMenu = 1;

            User& activeUser = DataUser::getUser(name);

            while(indexUserMenu != 0){

                if(DataUser::verifyUser(tempUser)){

                    userMenu();
                    log("Choose: ");
                    int menuChoose;
                    std::cin >> menuChoose;
    
                    switch (menuChoose)
                    {
                    case 1:
                        log("> Enter value: ");
                        int depositValue;
                        std::cin >> depositValue;
                        activeUser.deposit(depositValue);
                        break;

                    case 2:
                        log("> Enter value: ");
                        int withdrawValue;
                        std::cin >> withdrawValue;
                        activeUser.withdraw(withdrawValue);
                        break; 

                    case 3: {
                        string targetUser;
                        int value;
                        log("> Target Account: ");
                        std::cin >> targetUser;
                        log("> Value: ");
                        std::cin >> value;

                        User& targeted = DataUser::getUser(targetUser);

                        DataUser::transferIn(activeUser, targeted, value);
                        break;
                    }

                    case 4:
                        activeUser.printInfo();
                        break;

                    case 0:
                        log("Logging out...");
                        system("cls");
                        indexUserMenu = 0;
                        break;
                    default:
                        break;
                    }
                    
                } else{
                    logn("[Error] Account does not exist.");
                }
            }
            break;
        }
        case 0:
            logn("Program has been stopped...");
            return 0;

        default:
            logn("[Error] Choose the available menu number.");
            break;
        }

    }
}

void loginMenu(){
    logn("---------- Login ----------");
    logn("1. Enter ");
    logn("0. Exit ");
    logn("----------=======----------");
}

void userMenu(){
    logn("---------- Bank ----------");
    logn("1. Deposit ");
    logn("2. Withdraw ");
    logn("3. Transfer ");
    logn("4. Balance Info ");
    logn("0. Logout ");
    logn("----------======----------");
}