
#include <stdlib.h>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int mi;
string bname, password;
string password1, bname1;
int dmoney, dmoney1;
int mj = 1;
int maccoption;
void displayMenu()
{
    cout << "\t\tMain Menu\n";
    cout << "1. NEW ACCOUNT\n";
    cout << "2. MANAGE ACCOUNT\n";
    cout << "3. ACCOUNT BALANCE\n";
    cout << "4. DELETE ACCOUNT\n";
    cout << "5. EXIT\n";
    cout << "CHOOSE BETWEEN 1-5\n";
}
void createAccount(string &bname, string &password)
{

    string cacc;
    cout << "Do you want to create an account (yes or no)?\n";
    cin >> cacc;
    if (cacc == "yes" || cacc == "Yes" || cacc == "YES")
    {
        cout << "Enter your name:\n";
        cin >> bname;
        cout << "Enter your password:\n";
        cin >> password;
    }
    else if (cacc == "no" || cacc == "No" || cacc == "NO")
    {
        cout << "Exiting account creation.\n";
        return;
    }
    else
    {
        cout << "Invalid input. Please enter 'yes' or 'no'.\n";
        createAccount(bname, password); // Recursive call to handle invalid input
        return;
    }
}
void save_date(string &bname, string &password)
{
    ifstream checkfile(bname + ".txt");
    if (checkfile.is_open())
    {
        cout << "Account already exists. Please choose a different name \n";
        checkfile.close();
        return;
    }
    else
    {
        cout << "Account created successfully.\n";
        cout << "Your name is: " << bname << "\n";
        cout << "Your password is: " << password << "\n";
        cout << "Please remember your password for future access.\n";
        cout << "account created \n";
    }

    dmoney = 0;
    ofstream file;
    file.open(bname + ".txt");
    if (file.is_open())
    {
        file << bname << endl;
        file << password << endl;
        file << dmoney << endl;
        file.close();
    }
    else
    {
        cout << "Unable to open file";
    }
}
void get_date(string &bname1, string &password1, int &dmoney1)
{

    ifstream file;
    file.open(bname1 + ".txt");
    if (file.is_open())
    {

        getline(file, bname);
        getline(file, password);
        file >> dmoney1;
        if (password == password1 && bname == bname1)
        {
            cout << "sucsesfully login" << endl;
            mj = 1;
        }
        else
        {
            cout << "wrong password or user id try again" << endl;
            mj = 0;
        }

        file.close();
    }
    else
    {
        cout << "error" << endl;
    }
}
void input(string &bname1, string &password1)
{
    cout << "Enter your name:\n";
    cin >> bname1;
    cout << "Enter your password:\n";
    cin >> password1;
}
void macc(string &bname1, string &password1, int &dmoney1)
{
    ifstream file;
    file.open(bname1 + ".txt");

    string n, p;
    getline(file, n);
    getline(file, p);
    file >> dmoney;
    file.close();
    cout << "Welcome to the account management system, " << bname1 << endl;
    cout << "Your current balance is: " << dmoney << endl;
    do
    {
        cout << "1.deposit\n2.credit\n3.exit\nchoose betwwen 1 ,2 and 3" << endl;
        cin >> maccoption;
        switch (maccoption)
        {
        case 1:
        {
            ofstream file;
            file.open(bname1 + ".txt");
            if (file.is_open())
            {
                file << bname1 << endl;
                file << password1 << endl;
                cout << "Enter the amount to deposit:\n";
                cin >> dmoney1;
                dmoney += dmoney1;

                file << dmoney << endl;
                cout << "Amount deposited successfully.\n";
                file.close();
                dmoney1 = 0;
            }
            else
            {
                cout << "Unable to open file";
            }
            mj = 0;
            break;
        }
        case 2:
        {
            ofstream file;
            file.open(bname1 + ".txt");

            if (file.is_open())
            {
                file << bname1 << endl;
                file << password1 << endl;
                cout << "Enter the amount to withdraw:\n";
                cin >> dmoney1;
                if (dmoney1 < dmoney)
                {
                    dmoney -= dmoney1;

                    file << dmoney << endl;
                    cout << "Amount withdrawn successfully.\n";
                    file.close();
                    dmoney1 = 0;
                }
                else
                {
                    cout << "Insufficient balance. Please enter a valid amount.\n";
                }
            }
            mj = 0;
            break;
        }
        case 3:
        {
            cout << "exit\n";
            mj = 0;
            break;
        }
        default:
        {
            cout << "invalid input\n";
            mj = 1;
            break;
        }
        }
    } while (maccoption != 1 && maccoption != 2 && maccoption != 3);

    cout << "your current balance is: " << dmoney << endl;
}
void bal(string &bname1, string &password1)
{
    ifstream file;
    file.open(bname1 + ".txt");
    if (file.is_open())
    {

        getline(file, bname);
        getline(file, password);
        file >> dmoney1;
        if (password == password1 && bname == bname1)
        {
            string n, p;
            file.open(bname1 + ".txt");
            getline(file, n);
            getline(file, p);
            file >> dmoney;
            file.close();
            cout << "Welcome to the account management system, " << bname1 << endl;
            cout << "Your current balance is: " << dmoney << endl;
            system("pause");
            system("cls");
        }
        else
        {
            cout << "wrong password or user id try again" << endl;
        }

        file.close();
    }
    else
    {
        cout << "error" << endl;
    }
}
int main()
{
    bool a = 1;
    do
    {
        do
        {
            displayMenu();
            cin >> mi;
            system("cls");
            switch (mi)
            {
            case 1:
                createAccount(bname, password);
                save_date(bname, password);
                system("pause");
                system("cls");
                mi = 0;

                break;
            case 2:
                mj = 0;
                input(bname1, password1);
                get_date(bname1, password1, dmoney1);
                if (mj == 1)
                {
                    do
                    {
                        macc(bname1, password1, dmoney1);
                    } while (mj == 1);
                }
                system("pause");
                system("cls");
                break;
            case 3:
                input(bname1, password1);
                get_date(bname1, password1, dmoney1);
                bal(bname1, password1);
                break;

            case 4:
                input(bname1, password1);
                get_date(bname1, password1, dmoney1);
                if (mj == 1)
                {
                    bal(bname1, password1);
                    cout << "do you want to delete your account \n1.yes\n2.no " << endl;
                    int del;
                    cin >> del;
                    if (del == 1)
                    {
                        remove((bname1 + ".txt").c_str());
                        cout << "account deleted successfully" << endl;
                    }
                    else if (del == 2)
                    {
                        cout << "account not deleted" << endl;
                    }
                    else
                    {
                        cout << "invalid output" << endl;
                    }
                }
                else
                {
                    cout << "Account not found or incorrect credentials." << endl;
                }
                system("pause");
                system("cls");
                break;
            case 5:
                mj = 0;
                a = 0;
                system("pause");
                system("cls");
                break;
            default:
                cout << "Wrong input. Please try again.\n";
                system("pause");
                system("cls");
            }
        } while (mi > 5 || mi < 1);
    } while (a == 1);
    cout << "Thank you for using the program.\n";
    return 0;
}