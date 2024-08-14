// function.h

#ifndef FUNCTION_H
#define FUNCTION_H

#include<iostream>
#include<fstream>  //file handling
#include<iomanip>  //setw()
#include <windows.h>  //sleep
#include<conio.h>  //_getch
#include<time.h>   //time library

using namespace std;



template<class T>  //data type not defined
class bank
{
    T  deposit;
    char name[100], phone[100];
public:
    char pin[5];
    int accountno = 1, cred = 0, deb = 0;

    void Credit_debit();
    void show();
    void deposi(T dep);
    void withdraw(T dep);
    void account_status();
    T returnaccountno();
    T returndeposit();
    void thankyou() {
        cout << "\n||";
        cout << "\n\tTHANK YOU FOR USING OUR SERVICE!!!";
        cout << "\n||";
    };
    void loadings() {
        for (int i = 1; i <= 100; ++i)
        {
            system("cls");
            cout << "\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tBANK MANAGEMENT SYSTEM";
            cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\tLOADING " << i << "%";
            cout << endl << endl;
            cout << "\t";
            for (int j = 0; j < i + 1; j++)
            {
                cout << "|";
            }
            Sleep(20);
            if (i == 100)
                Sleep(2000);
        }
    };
    void create();
    void members();
    bank operator++();
    T returncred();
    T returndeb();
};

class loading {
public:
    void loadings();
};

class members1 {
public:
    bank<int> k;
    void printmembers();
};

class showinfo {
public:
    void show(bank<int>& acc);
};

class acca {
    bank<int>* aac;
public:
    acca(bank<int>* aaac);
};

class crt_acc {
public:
    void creating_account();
};

class info {
public:
    void bankdata();
};

class remove_acc {
public:
    void removeacc(int n);
};

class balance_check {
public:
    void balanceenq(int n);
};

class dep_wid {
public:
    void depamount(int n, int c);
    void account_transaction(int n, int b);
    void bank_statement(int n);
};

class Cashier : public crt_acc, public balance_check, public dep_wid, public remove_acc {
public:
    char cpin[4];
    int id, salary;
    string prof;
    char cname[100], clname[100], cphone[100];

    void addemp();
    void employee_status();
    int returnid();
};

class Manager : public info, public Cashier {
public:
    string pins;
    void creating_employee();
    void employeedata();
    void rem(int n);
    int ser();
};

#endif
