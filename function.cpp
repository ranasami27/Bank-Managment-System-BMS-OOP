// function.cpp
#include "function.h"
fstream file;

template<class T>
void bank<T>::Credit_debit() {
    int sf;
cd:
    cout << "\nWhich Card do you want:";
    cout << "\n1. Debit Card";
    cout << "\n2. Credit Card";
    cout << "\n3. Both";
    cout << "\n4. None";
    cout << "\nEnter your choice = ";
    cin >> sf;
    switch (sf)
    {
    case 1:
        deb++;
        cout << "Debit Card issued to your account.";
        break;
    case 2:
        cred++;
        cout << "Credit Card issued to your account.";
        break;
    case 3:
        cred++;
        deb++;
        cout << "Debit and Credit card issued to your account.";
    case 4:
        break;
    default:
        cout << "\nEnter a valid option.";
        goto cd;
    }
}

template<class T>
void bank<T>::show() {
    cout << "\nAccount Name: ";
    cout << name;
    cout << "\nAccount Number: ";
    cout << accountno;
    cout << "\nAccount Balance: ";
    cout << deposit;
}

template<class T>
void bank<T>::deposi(T dep) {
    deposit = deposit + dep;
}

template<class T>
void bank<T>::withdraw(T dep) {
    deposit = deposit - dep;
}

template<class T>
void bank<T>::account_status() {
    cout << setw(6) << accountno << setw(20);
    cout << name << setw(25);
    cout << phone << setw(12);
    cout << deposit << setw(10);
    cout << cred << setw(20);
    cout << deb << endl;
}

template<class T>
T bank<T>::returnaccountno() {   //getter functions
    return accountno;
}

template<class T>
T bank<T>::returndeposit() {
    return deposit;
}



template<class T>
void bank<T>::create() {
    cout << "\n\n***************** NEW ACCOUNT FORM *****************\n";
pinnn:
    int count = 0;
    cout << "\nEnter your four digit pin: ";
    cin >> pin;

    for (int i = 0; i < strlen(pin); i++)
    {
        if (pin[i] >= '0' && pin[i] <= '9')
        {
            count++;
        }
    }
    if (strlen(pin) != 4 || count != strlen(pin))
    {
        cout << "\nEnter a valid pin.";
        goto pinnn;
    }
    else
    {
        int a;
        int b;
        cout << "\nEnter Your Name: ";
        cin.ignore();
        cin.getline(name, 100);
        srand(time(0));
        accountno = rand();
        cout << "\nYour account number is: " << accountno;
        cout << "\nEnter Your Phone Number: ";
        cin.ignore();
        cin.getline(phone, 100);
        cout << "\nEnter The Amount to Deposit: ";
        cin >> deposit;

    }
}

template<class T>
void bank<T>::members() {
    system("COLOR 5F");
    cout << "\n\n\n\n\n\n\n\n\n\n\n\t\tWelcome to the BANK MANAGEMENT SYSTEM";
    cout << "\n\n\n\t\n Muhammad Subhan (001) ";
    Sleep(6000);
    system("cls");
}

template<class T>
bank<T> bank<T>::operator++() {
    deposit++;
    return *this;
}

template<class T>
T bank<T>::returncred() {
    return cred;
}

template<class T>
T bank<T>::returndeb() {
    return deb;
}

void loading::loadings()  //function overriding polymorphism
{
    cout << "\n\n***************** BANK MANAGEMENT *****************\n";
    cout << "\nLogin as\n1. USER";
    cout << "\n2. CASHIER";
    cout << "\n3. BANK MANAGER";
    cout << "\n4. EXIT THE PROGRAM";
    cout << "\n**";
}

void members1::printmembers() {  //composition
    k.members();
}

void showinfo::show(bank<int>& acc) {  //association
    acc.show();
}

acca::acca(bank<int>* aaac) {       //aggregation
    aaac = aac;
}

void crt_acc::creating_account()
{
    ofstream crtaccount;
    ifstream asss;
    bank<int> OBJ;
    crtaccount.open("Bank Data.txt", ios::binary | ios::app);
    OBJ.create();

    OBJ.Credit_debit();
    crtaccount.write(reinterpret_cast<char*> (&OBJ), sizeof(bank<int>));
    crtaccount.close();
}

void info::bankdata()
{
    bank<int> ba;
    ifstream all;
    all.open("Bank Data.txt", ios::binary);
    if (!all)
    {
        cout << "\nNo file found. Press Enter.";
        return;
    }

    system("cls");
    cout << "\n\n\t\t\t\t\tACCOUNT HOLDERS";
    cout << "\n*";
    cout << "\nACC NO.        NAME                       PHONE NO.     Balance     Credit Card       Debit Card";
    cout << "\n*\n";
    while (all.read(reinterpret_cast<char*> (&ba), sizeof(bank<int>)))
    {
        ba.account_status();
    }
    all.close();
}

void remove_acc::removeacc(int n)
{
    bank<int> ba;
    ifstream inFile;
    char as[5];
    ofstream outFile;
    inFile.open("Bank Data.txt", ios::binary);
    if (!inFile)
    {
        cout << "File could not be open !! Press any Key...";
        return;
    }
    outFile.open("Temp.txt", ios::binary);
    inFile.seekg(0, ios::beg);


    inFile.seekg(0, ios::beg);
    while (inFile.read(reinterpret_cast<char*> (&ba), sizeof(bank<int>)))
    {
        if (ba.returnaccountno() != n)
        {
            outFile.write(reinterpret_cast<char*> (&ba), sizeof(bank<int>));
        }
    }
    inFile.close();
    outFile.close();
    remove("Bank Data.txt");
    rename("Temp.txt", "Bank Data.txt");
    cout << "\n\n\tRecord Deleted ..";


}

void balance_check::balanceenq(int n)
{
    char A[5];
    showinfo sf;
    bank<int> ba;
    bool sfs = false;
    ifstream inFile;
    inFile.open("Bank Data.txt", ios::binary);
    if (!inFile)
    {
        cout << "No file found. Press Enter.";
        return;
    }

    while (inFile.read(reinterpret_cast<char*> (&ba), sizeof(bank<int>)))
    {
        if (ba.returnaccountno() == n)
        {

            cout << "Enter your four digit pin: ";
            cin >> A;

            if (strcmp(A, ba.pin) == 0)
            {

                cout << "\n**ACCOUNT STATUS\n";
                sf.show(ba);

            }
            else {
                cout << "Wrong pin.";
            }
            sfs = true;
        }
    }
    inFile.close();
    if (sfs == false)
        cout << "\n\nAccount does not exist";
}

void dep_wid::depamount(int n, int c)
{
    fstream all;
    all.open("Bank statement.txt", std::fstream::in | std::fstream::out | std::fstream::app);
    switch (c)
    {
    case 1:
    {
        int amt;
        bool found = false;
        bank<int> ban;
        fstream File;

        File.open("Bank Data.txt", ios::binary | ios::in | ios::out);
        if (!File)
        {
            cout << "File could not be open !! Press any Key...";
            return;
        }
        while (!File.eof() && found == false)
        {
            File.read(reinterpret_cast<char*> (&ban), sizeof(bank<int>));
            if (ban.returnaccountno() == n)
            {
                ban.show();

                cout << "\nEnter your pin = ";
                char as[5];
                cin >> as;
                if (strcmp(as, ban.pin) == 0)
                {
                    cout << "\n\nEnter the Amount to Deposit: ";
                    cin >> amt;
                    ban.deposi(amt);
                }
                else
                    cout << "\nWrong pin";
                int pos = (-1) * static_cast<int>(sizeof(ban));
                File.seekp(pos, ios::cur);
                File.write(reinterpret_cast<char*> (&ban), sizeof(bank<int>));
                cout << "\n\n Record Updated!";
                found = true;

                all << "\n " << n << " " << amt;

                cout << endl;
            }
        }
        File.close();
        if (found == false)
            cout << "\n\n Record Not Found ";
        break;
    }

    case 2:
    {

        int amt;
        bool fdj = false;
        bank<int> ban;
        fstream File;
        File.open("Bank Data.txt", ios::binary | ios::in | ios::out);
        if (!File)
        {
            cout << "File could not be open !! Press any Key...";
            return;
        }
        while (!File.eof() && fdj == false)
        {
            File.read(reinterpret_cast<char*> (&ban), sizeof(bank<int>));
            if (ban.returnaccountno() == n)
            {
                ban.show();


                cout << "\nEnter your pin = ";
                char as[5];
                cin >> as;
                if (strcmp(as, ban.pin) == 0)
                {
                    cout << "\n\nEnter the Amount to Withdraw: ";
                    cin >> amt;

                    int bal = ban.returndeposit() - amt;
                    if (bal < 500)
                        cout << "Insufficient balance";
                    else
                        ban.withdraw(amt);
                }
                else
                    cout << "\nWrong pin.";

                int pos = (-1) * static_cast<int>(sizeof(ban));
                File.seekp(pos, ios::cur);
                File.write(reinterpret_cast<char*> (&ban), sizeof(bank<int>));
                cout << "\n\n Record Updated!";
                all << "\n" << n << " " << -amt;

                fdj = true;



            }
        }
        File.close();
        if (fdj == false)
            cout << "\n\n No record ";
        break;
    }
    }
}
void dep_wid::account_transaction(int n, int b)
{
    int amt;
    fstream all;
    bool found = false;
    all.open("Bank statement.txt", std::fstream::in | std::fstream::out | std::fstream::app);
    bool fdj = false;
    bank<int> ban;
    fstream File;
    File.open("Bank Data.txt", ios::binary | ios::in | ios::out);
    if (!File)
    {
        cout << "File could not be open !! Press any Key...";
        return;
    }
    while (!File.eof() && fdj == false)
    {
        File.read(reinterpret_cast<char*> (&ban), sizeof(bank<int>));
        if (ban.returnaccountno() == n)
        {
            ban.show();


            cout << "\nEnter your pin = ";
            char as[5];
            cin >> as;
            if (strcmp(as, ban.pin) == 0)
            {


                cout << "\n\nEnter the Amount to Transfer: ";
                cin >> amt;

                int bal = ban.returndeposit() - amt;

                if (bal < 500)
                    cout << "Insufficient balance";
                else
                    ban.withdraw(amt);

            }
            else
                cout << "\nWrong pin.";

            int pos = (-1) * static_cast<int>(sizeof(ban));
            File.seekp(pos, ios::cur);
            File.write(reinterpret_cast<char*> (&ban), sizeof(bank<int>));
            cout << "\n\n Record Updated!";
            all << "\n" << n << " " << -amt;
            all << endl;
            fdj = true;



        }
    }
    File.close();
    if (fdj == false)
        cout << "\n\n No record ";

    File.open("Bank Data.txt", ios::binary | ios::in | ios::out);
    if (!File)
    {
        cout << "File could not be open !! Press any Key...";
        return;
    }
    while (!File.eof() && found == false)
    {
        File.read(reinterpret_cast<char*> (&ban), sizeof(bank<int>));
        if (ban.returnaccountno() == b)
        {
            ban.deposi(amt);
            int pos = (-1) * static_cast<int>(sizeof(ban));
            File.seekp(pos, ios::cur);
            File.write(reinterpret_cast<char*> (&ban), sizeof(bank<int>));
            cout << "\n\n Record Updated!";
            found = true;

            all << n << " " << amt << endl;

        }
    }
    File.close();
    if (found == false)
        cout << "\n\n Record Not Found ";
}

void dep_wid::bank_statement(int n)
{
    fstream all;
    int amt, a;
    all.open("Bank statement.txt", std::fstream::in | std::fstream::out | std::fstream::app);
    cout << "\n**\n";
    cout << "\n  Account No         Money              \n";
    cout << "\n**";
    while (!all.eof())
    {
        all >> a;
        all >> amt;
        if (a == n)
        {
            cout << endl << "  " << a << setw(16) << amt;
        }

    }
    file.close();
}

void Cashier::addemp()
{
pi:
    int ccount = 0;
    cout << "\nEnter your four digit pin: ";
    cin >> cpin;

    for (int i = 0; i < strlen(cpin); i++)
    {
        if (cpin[i] >= '0' && cpin[i] <= '9')
        {
            ccount++;
        }
    }
    if (strlen(cpin) != 4 || ccount != strlen(cpin))
    {
        cout << "\nEnter a valid pin.";
        goto pi;
    }

    cout << "Enter the employee's First name: ";
    cin.ignore();
    cin.getline(cname, 100);
    cout << "Enter the employee's last name: ";

    cin.getline(clname, 100);
    cout << "Enter Phone number: ";
    cin.ignore();
    cin.getline(cphone, 100);
    cout << "Enter the salary: ";
    cin >> salary;
    cout << "Job: ";
    cin >> prof;
    srand(time(0));
    id = rand();
    cout << "Your id number is: " << id;
}

void Cashier::employee_status()
{
    cout << setw(6) << id << setw(16);
    cout << cname << setw(19) << clname << setw(23);
    cout << cphone << setw(20);
    cout << prof << setw(15);
    cout << salary << endl;
}

int Cashier::returnid()
{
    return id;
}

void Manager::creating_employee()
{
    Cashier c;

    file.open("EMPLOYEE.txt", ios::binary | ios::app);
    if (!file) {
        cout << "ERROR IN CREATING FILE\n";
        return;
    }
    c.addemp();
    //write into file
    file << "\n";
    file << c.id << " " << c.cname << " " << c.clname << " " << c.cphone << " " << c.prof << " " << c.salary << " " << c.cpin;
    file.close();
    cout << "\nRecord added successfully.\n";
}

void Manager::employeedata()
{
    Cashier c;

    file.open("EMPLOYEE.txt", ios::binary | ios::in);
    if (!file)
    {
        cout << "\nNo file found. Press Enter.";
        return;
    }
    system("cls");
    cout << "\n\n\t\t\t\t\t Bank Employees";
    cout << "\n*";
    cout << "\n ID.        First NAME          Last Name              PHONE NO.          Profession         Salary";
    cout << "\n*\n";
    while (!file.eof()) {
        file >> c.id;
        file >> c.cname >> c.clname;
        file >> c.cphone;
        file >> c.prof;
        file >> c.salary;
        file >> c.cpin;
        c.employee_status();
    }
    file.close();
}
void rem(int n) {
    Cashier c;
    ofstream d;
    file.open("EMPLOYEE.txt", ios::binary | ios::in);
    if (!file)
    {
        cout << "\nNo file.";
    }
    d.open("temp.txt", ios::binary);

    while (!file.eof()) {
        file >> c.id;
        file >> c.cname >> c.clname;
        file >> c.cphone;
        file >> c.prof;
        file >> c.salary;
        file >> c.cpin;
        if (c.id != n)
        {
            d << "\n";
            d << c.id << " " << c.cname << " " << c.clname << " " << c.cphone << " " << c.prof << " " << c.salary << " " << c.cpin;
        }
    }

    d.close();
    file.close();
    remove("EMPLOYEE.txt");
    rename("temp.txt", "EMPLOYEE.txt");
    cout << "\n\n\tRecord Deleted ..";
}


void Manager::rem(int n)
{
    Cashier c;
    ofstream d;
    file.open("EMPLOYEE.txt", ios::binary | ios::in);
    if (!file)
    {
        cout << "\nNo file.";
    }
    d.open("temp.txt", ios::binary);

    while (!file.eof()) {
        file >> c.id;
        file >> c.cname >> c.clname;
        file >> c.cphone;
        file >> c.prof;
        file >> c.salary;
        file >> c.cpin;
        if (c.id != n)
        {
            d << "\n";
            d << c.id << " " << c.cname << " " << c.clname << " " << c.cphone << " " << c.prof << " " << c.salary << " " << c.cpin;
        }
    }

    d.close();
    file.close();
    remove("EMPLOYEE.txt");
    rename("temp.txt", "EMPLOYEE.txt");
    cout << "\n\n\tRecord Deleted ..";
}

int Manager :: ser()
{
    char n[5];
    Cashier c;
    int f;
    cout << "\nEnter your Employee id: ";
    cin >> f;
    file.open("EMPLOYEE.txt", ios::binary | ios::in);
    if (!file)
    {
        cout << "\nNo file found. Press Enter.";
        return 1;
    }

    while (!file.eof()) {
        file >> c.id;
        file >> c.cname >> c.clname;
        file >> c.cphone;
        file >> c.prof;
        file >> c.salary;
        file >> c.cpin;
        if (c.id == f)
        {
            cout << "\nEnter your pin: ";
            cin.ignore();
            cin.getline(n, 5);
            if (strcmp(n, c.cpin) == 0)
            {
                system("cls");
                cout << "\nID number: " << c.id;
                cout << "\nName: " << c.cname << " " << c.clname;
                cout << "\nLogged in as cashier\n ";
                Sleep(4000);
            }
        }
        else
        {
            cout << "\nNo user found with this Id. Create a Employee account first in admin menu.";
            file.close();
            return 1;
        }
       
    }
    file.close();
    return 0;
}
