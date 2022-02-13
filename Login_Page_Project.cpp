#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

void Login();
void Register();
void Forgot();

int main()
{
    int choice;
    cout << "\t\t\t*************************************************************************\n\n";
    cout << "\t\t\t                     Welcome To LOGIN Page                                \n\n";
    cout << "\t\t\t*******************            Menu         ******************************\n\n";
    cout << "\t\t | Press 1 LOGIN                     |\n";
    cout << "\t\t | Press 2 REGISTER                  |\n";
    cout << "\t\t | Press 3 FORGOT                    |\n";
    cout << "\t\t | Press 4 EXIT                      |\n\n";
    cout << "\t\t Please Enter Your Choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        Login();
        break;
    case 2:
        Register();
        break;
    case 3:
        Forgot();
        break;
    case 4:
        system("cls");
        cout << "\t\t\tThank You";
        break;
    default:
        system("cls");
        cout << "\t\t Please Enter Valid Choice";
        main();
    }
    return 0;
}
void Login()
{
    int count = 0;
    string userId, password, id, pass;
    system("cls");
    cout << "\t\t\t Please Enter LOGIN Details\n";
    cout << "\t\t\t Enter USERNAME: ";
    cin >> userId;
    cout << "\t\t\t Enter PASSWORD: ";
    cin >> password;

    ifstream input("records.txt");

    while (input >> id >> pass)
    {
        if (id == userId && pass == password)
        {
            count = 1;
            system("cls");
        }
    }
    input.close();
    if (count == 1)
    {
        cout << "\t\t\t LOGIN Sucessful\n";
        main();
    }
    else
        cout << "\t\t\t Login Not Sucessful enter correct Userid and password";
}

void Register()
{
    string ruserId, rpassword, rid, rpass;
    system("cls");
    cout << "\t\t\t Enter following details for Registration details\n\n";
    cout << "\t\t\t Enter USERNAME: ";
    cin >> ruserId;
    cout << "\t\t\t Enter PASSWORD: ";
    cin >> rpassword;

    ofstream f1("records.txt", ios::app);
    f1 << ruserId << ' ' << rpassword << endl;
    cout << "\n\t\t\t Registration Sucessful\n";
    main();
}

void Forgot()
{
    int option;
    cout << "\t\t\t You forgot password? No worries!\n";
    cout << "\t\t\t Press 1 For search userid by username";
    cout << "\t\t\t Press 2 go back to main menu";
    cout << "\t\t\t Enter Your choice: ";
    cin >> option;

    switch (option)
    {
    case 1:
    {
        int count = 0;
        string suserId, spass, sid;
        cout << "\t\t\t Enter userid which you remember: ";
        cin >> suserId;

        ifstream f2("records.txt");
        while (f2 >> sid >> spass)
        {
            if (suserId == sid)
            {
                count = 1;
            }
        }
        f2.close();
        if (count == 1)
        {
            cout << "\t\t\t Your Account Found";
            cout << "\t\t\t Your password is: " << spass;
            main();
        }
        else
        {
            cout << "Your Account Not found ";
        }
    }
    }
}
