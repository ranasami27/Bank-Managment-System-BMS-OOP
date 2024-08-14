#include "function.h"

int main()
{
    int cc;
    int lass;
    Manager m;
    loading l;
    members1 mm;
    bank<int> sub;

    dep_wid dw;
    balance_check bc;
    info inf;
    crt_acc ce;
    int c;
    int sdd;
    remove_acc re;
    int user, cashier, manager;
    int Accountnumber, Accountnumber2;
    mm.printmembers();
    sub.loadings();
    int tr;
   
    system("cls");
    cout << "\n\n\n\t  WELCOME!!!";
    cout << "\n**\n";
start:
    system("cls");
    l.loadings();
    acca* per = new acca(&sub);
strt:
    edu:
    cout << "\nSelect an Option: ";
    cin >> c;
    //using switch case to call function as per the user input
    switch (c)
    {
    case 1:  //user
    {
    loop1:
        system("cls");
        cout << "\n**USER\n";
        cout << "1. Balance Inquiry";
        cout << "\n2. Balance Withdraw";
        cout << "\n3. Balance Deposit";
        cout << "\n4. Money Transfer";
        cout << "\n5. Bank Statement";
        cout << "\n6. Main menu";
    cas:
        cout << "\nEnter an option: ";
        cin >> user;
        switch (user)
        {
        case 1:
            cout << "Enter your Account number: ";
            cin >> Accountnumber;
            bc.balanceenq(Accountnumber);
            break;
        case 2:
            cout << "Enter your Account number: ";
            cin >> Accountnumber;
            dw.depamount(Accountnumber, 2);
            break;
        case 3:
            cout << "Enter your Account number: ";
            cin >> Accountnumber;
            dw.depamount(Accountnumber, 1);
            break;
        case 4:
            cout << "Enter your Account number: ";
            cin >> Accountnumber;
            cout << "Enter the Account number of receiver: ";
            cin >> Accountnumber2;
            dw.account_transaction(Accountnumber, Accountnumber2);
            break;
        case 5:
            cout << "Enter your Account number: ";
            cin >> Accountnumber;
            dw.bank_statement(Accountnumber);
            break;
        case 6:
            goto start;
            break;
        default:
            cout << "\nEnter a valid option.";
            goto cas;
        }
        cout << "\nPress 1 to repeat, and 0 to exit the code: ";
        cin >> lass;
        if (lass == 1)
        {
            system("cls");
            goto loop1;
        }
        else
            break;
    }
    case 2:  //cashier
    {
        int cas = 0;
    po:

        char ch1;
        string ppin1 = "";
        cout << "\nEnter the admin pin (1122): ";
        ch1 = _getch();
        while (ch1 != 13) {
            if (ch1 == 8 && ppin1.length() > 0) {
                cout << "\b \b";
                ppin1.pop_back();
            }
            else {
                ppin1.push_back(ch1);
                cout << '*';
            }
            ch1 = _getch();
        }
        if (ppin1 == "1122")
        {
            if (m.ser() == 1)
            {
                goto edu;
            }
        loop2:
            system("cls");
            cout << "\n**Cashier\n";
            cout << "1. Create Account";
            cout << "\n2. Delete Account";
            cout << "\n3. Main menu";

        use:
            cout << "\nEnter an option: ";
            cin >> cashier;

            switch (cashier) {
            case 1:
                ce.creating_account();
                break;
            case 2:
                cout << "Enter your Account number: ";
                cin >> Accountnumber;
                re.removeacc(Accountnumber);
                break;
            case 3:
                goto start;
                break;
            default:
                cout << "Enter a valid option.";
                goto use;
            }
            cout << "Press 1 to repeat, and 0 to exit the code: ";
            cin >> lass;
            if (lass == 1)
            {
                system("cls");
                goto loop2;
            }
            else
                break;
        }
        else {
            cout << "\nWrong pin. Try Again";
            cas++;
            if (cas == 2)
            {
                cout << "\nThis is your last Try.";
            }
            if (cas < 3)
                goto po;
            else
            {
                cout << "\n\b\b\bWrong Pin Entered too many times.\b";
                _exit(0);
            }
        }
    }
    case 3:      //manager
    {
        int cas = 0;
    pii:
        char ch;
        string ppin = "";
        cout << "\nEnter the Manager password (sad123): ";
        ch = _getch();
        while (ch != 13) {
            if (ch == 8 && ppin.length() > 0) {
                cout << "\b \b";
                ppin.pop_back();
            }
            else {
                ppin.push_back(ch);
                cout << '*';
            }
            ch = _getch();
        }
        if (ppin == "sad123")
        {

        loop3:
            system("cls");
            cout << "\n**Manager\n";
            cout << "1. Add employee";
            cout << "\n2. Remove Employee";
            cout << "\n3. Employee data";
            cout << "\n4. Account holders";
            cout << "\n5. Main menu";
        mannn:
            cout << "\nEnter your option: ";
            cin >> manager;

            switch (manager)
            {
            case 1:
                m.creating_employee();
                break;
            case 2:
                cout << "Enter employee id to remove from list: ";
                cin >> sdd;
                m.rem(sdd);
                break;
            case 3:
                m.employeedata();
                break;
            case 4:
                inf.bankdata();
                break;
            case 5:
                goto start;
                break;
            default:
                cout << "Enter a valid option.";
                goto mannn;
            }
            cout << "\nPress 1 to repeat, and 0 to exit the code: ";
            cin >> lass;
            if (lass == 1)
            {
                system("cls");
                goto loop3;
            }
            else
                break;
        }
        else
        {
            cout << "\nWrong pin. Try Again";
            cas++;
            if (cas == 2)
            {
                cout << "\nThis is your last Try.";
            }
            if (cas < 3)
                goto pii;
            else
            {
                cout << "\n\b\b\bWrong Pin Entered too many times.\b";
                _exit(0);
            }

        }
    }
    case 4:
    {
        sub.thankyou();
        return 0;
        break;
    }
    default:
        cout << "Enter a valid option.";
        goto strt;
    }
}