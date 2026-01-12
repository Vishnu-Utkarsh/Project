#include <ctime>
#include <iomanip>
#include <string>

#include "Template.hpp"
#include "data.cpp"
#include "operation.cpp"

void displayOptions()
{
    cout << std::endl;
    #ifdef _WIN32
        std::system("cls"); // For Windows
    #else
        // Assume POSIX (Linux, macOS, etc.)
        std::system("clear"); 
    #endif

    std::cout << "----------------------------------------------------" << std::endl;
    std::cout << "Enter 1 to create new user account:" << std::endl;
    std::cout << "Enter 2 to dipplay user's data:" << std::endl;
    std::cout << "Enter 3 to login to your account:" << std::endl;
    std::cout << "Enter -1 to Exit:" << std::endl;
    std::cout << std::endl;
}

bool operate(int task)
{
    switch(task)
    {
        case 1:
        {
            createAccount();
            break;
        }
        case 2:
        {
            displayUserData();
            break;
        }
        case 3:
        {
            userLogin();
            break;
        }
        case -1:
        {
            saveUserData("userData.csv");

            std::time_t now = std::time(0);
            std::tm *local_time_struct = std::localtime(&now);

            std::cout << "\n\n Data Updated by: " << std::put_time(local_time_struct, "%Y-%m-%d %H:%M:%S");
            cout << "\n~~Exit~~";

            return false;
            break;
        }
        default:
        {
            std::cout << "Enter valid operation !" << std::endl;
        }
    }
    return true;
}

int main()
{
    fastio;
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif

    readUserData("userData.csv");

    while(true)
    {
        int T;
        std::cin >> T;
        displayOptions();

        if(! operate(T))
            return 0;
    }
}