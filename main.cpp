#include "Template.hpp"
#include "user.hpp"

void displayOptions()
{
    #ifdef _WIN32
        std::system("cls"); // For Windows
    #else
        // Assume POSIX (Linux, macOS, etc.)
        std::system("clear"); 
    #endif

    cout << "----------------------------------------------------" << endl;
    cout << "Enter 1 to enter user data:" << endl;
    cout << "Enter 2 to dipplay all user's data:" << endl;
    cout << "Enter 3 to login to user's profile:" << endl;
    cout << "Enter -1 to Exit:" << endl;
    cout << endl;
}

bool operate(int task)
{
    switch(task)
    {
        case 1:
        {
            int n;
            cin >> n;

            for (int i = 0; i < n; i++)
            {
                int x, r;
                string y, z;
                cin >> x >> y >> z >> r;

                User user(x, y, z);

                if(r != -1) user.updateRating(r);
                debug(user);
                print(user);
            }
            break;
        }
        case 2:
        {
            string name, pass;

            cout << endl << "Enter userID: ";
            cin >> name;
            cout << endl << "Enter password: ";
            cin >> pass;

            break;
        }
        case -1:
        {
            return false;
            break;
        }
        default:
        {
            cout << "Enter valid operation !" << endl;
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

    while(true)
    {
        int T;
        cin >> T;
        displayOptions();

        if(! operate(T))
            return 0;
    }
}