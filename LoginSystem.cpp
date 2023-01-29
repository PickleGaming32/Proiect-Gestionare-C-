#include <iostream>
#include <windows.h>
#include <cstring>
#include <fstream>

using namespace std;

#pragma warning(disable: 4996)

void showmenu(), login();

struct USER{
    char *username = new char();
    char *password = new char();
};

int x, poz;
USER mainuser;
USER *user = new USER[100];

void changeusername()
{
    char newusername[100];
    system("CLS");
    int i;
    cout  << "====== CHANGE USERNAME ====== \n \n";
    cin.get();
    for (i = 0; i < x; i++)
        if ((strcmp(user[i].username,mainuser.username) == 0) && (strcmp(user[i].password, mainuser.password) == 0))
        {
            cout << "Enter new username: ";
            cin.getline(newusername,99);
            strcpy(user[i].username,newusername);
            strcpy(mainuser.username,newusername);
            cout << endl << "Username successfully changed." << endl;
            system("Pause");
            showmenu();
        }
}

void changepassword()
{
    char newpassword[100];
    system("CLS");
    int i;
    cout << "====== CHANGE PASSWORD ====== \n \n";
    cin.get();
    for (i = 0; i < x; i++)
        if ((strcmp(user[i].username,mainuser.username) == 0) && (strcmp(user[i].password, mainuser.password) == 0))
        {
            cout << "Enter new password: ";
            cin.getline(newpassword,99);
            strcpy(user[i].password,newpassword);
            strcpy(mainuser.password,newpassword);
            cout << endl << "Password successfully changed." << endl;
            system("Pause");
            showmenu();
        }

}

void signup()
{
    system("CLS");
    cout << "====== SIGN UP ====== \n \n";
    char select;
    char tempuser[100],temppass[100];
    int i;
    cout << "Enter username: ";
    cin.getline(tempuser,100);
    for (i = 0; i < x; i++)
        if (strcmp(user[i].username, tempuser) == 0)
        {
            cout << "User name has already been taken! \nTry again? [y/n] \n \n";
            cin >> select;
            if(select == 'y')
                signup();
            else
                login();
        }
    cout << "Enter password: ";
    cin.getline(temppass,100);
    strcpy(user[x].username,tempuser);
    strcpy(user[x].password,temppass);
    x++;
    cout << "New user successfully registered!" << endl << endl;
    system("Pause");
}

void login()
{
    int i, cond = 0;
    char select;
    system("CLS");
    cout << "====== LOGIN ====== \n \n";
    cout << "Enter username: ";
    cin.getline(mainuser.username,100);
    cout << "Enter password: ";
    cin.getline(mainuser.password,100);
    for (i = 0; i < x; i++)
        if ((strcmp(user[i].username,mainuser.username) == 0) && (strcmp(user[i].password, mainuser.password) == 0))
        {
            cond = 1;
            strcpy(mainuser.username,user[i].username);
            strcpy(mainuser.password,user[i].password);
            break;
        }
    if (cond == 1)
    {
        system("CLS");
        cout << endl << "User found!" << endl << endl;
        cout << "Logging in";
        Sleep(500);
        cout << ".";
        Sleep(500);
        cout << ".";
        Sleep(500);
        cout << ".";
        Sleep(500);
        cout << endl << endl;
        system("CLS");
        cout << "Successfully logged in!" << endl << endl;
        system("Pause");
    }
    else
    {
        system("CLS");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
        cout << endl << "Incorrect username or password." << endl << endl << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
        cout << "Would you like to sign up?  [y/n]" << endl << endl;
        cin >> select;
        switch (select) {
    case 'y':
        cin.get();
        signup();
        login();
        break;
    case 'n':
        cin.get();
        login();
        break;
    default:
        cout << "EROARE" << endl;
        break;
        }
    }
}

void save()
{
    int i;
    ofstream file("users.txt");
    int copie = x;
    file << copie << endl;
    for (i = 0; i < x; i++)
    {
        file << user[i].username << endl;
        file << user[i].password << endl;
    }
}


void showmenu()
{
    system("CLS");
    int select;
    cout << "====== MENU ====== \n \n";
    cout << "[1] Change Username \n";
    cout << "[2] Change Password \n";
    cout << endl << "[3] Exit \n \n";
    cin >> select;
    switch (select)
    {
    case 1:
        changeusername();
        showmenu();
        break;
    case 2:
        changepassword();
        showmenu();
        break;
    case 3:
        system("CLS");
        save();
        exit(32);
        break;
    }
}

void startupLogin()
{
    ifstream file("users.txt");
    int i;
    file >> x;
    file.get();
    for (i = 0; i < x; i++)
    {
        file.getline(user[i].username,100);
        file.getline(user[i].password,100);
    }
}

