#include <iostream>
#include <cstdlib>
#include <vector>
#include <map>
using namespace std;

#define MIN_BALANCE 500

class InsufficientFunds {};

class Account {
    public:
        Account() {}
        Account(string fname, string lname, float balance);
        long getAccNo() { return accountNumber; }
        string getFirstName() { return firstName; }
        string getLastName() { return lastName; }
        float getBalance() { return balance; }
        void Deposit(float amount);
        void Withdraw(float amount);
        static void setLastAccountNumber(long accountNumber) { NextAccountNumber = accountNumber; }
        static long getLastAccountNumber() { return NextAccountNumber; }
        friend ostream &operator<<(ostream &os, Account &acc);
    private:
        long accountNumber;
        string firstName;
        string lastName;
        float balance;
        static long NextAccountNumber;
};

long Account::NextAccountNumber = 0;

class Bank {
    public:
        Account OpenAccount(string fname, string lname, float balance);
        Account BalanceEnquiry(long accountNumber);
        Account Deposit(long accountNumber, float amount);
        Account Withdraw(long accountNumber, float amount);
        void CloseAccount(long accountNumber);
        void ShowAllAccounts();
    private:
        map<long, Account> accounts;
};

int main() {
    Bank b;
    Account acc;
    int choice;
    string fname, lname;
    long accountNumber;
    float balance, amount;

    cout << "\t***Banking System***" << endl;
    do {
        cout<<"\nSelect one option below:";
        cout<<"\n1. Open an Account";
        cout<<"\n2. Balance Enquiry";
        cout<<"\n3. Deposit";
        cout<<"\n4. Withdrawal";
        cout<<"\n5. Close an Account";
        cout<<"\n6. Show All Accounts";
        cout<<"\n0. Quit";
        cout<<"\nEnter your choice: ";
        cin>>choice;
        
        switch (choice) {
        case 1:
            cout<<"Enter First Name: ";
            cin>>fname;
            cout<<"Enter Last Name: ";
            cin>>lname;
            cout<<"Enter initial Balance: ";
            cin>>balance;
            acc = b.OpenAccount(fname, lname, balance);
            cout<<"\nCongratulations! Account is Created\n";
            cout<<acc;
            break;
        case 2:
            cout<<"Enter Account Number: ";
            cin >> accountNumber;
            acc = b.BalanceEnquiry(accountNumber);
            cout<<"\nYour Account Details\n";
            cout<<acc;
            break;
        case 3:
            cout<<"Enter Account Number: ";
            cin>>accountNumber;
            cout<<"Enter Amount: ";
            cin>>amount;
            acc = b.Deposit(accountNumber, amount);
            cout<<"\nAmount Deposited\n";
            cout<<acc;
            break;
        case 4:
            cout<<"Enter Account Number: ";
            cin>>accountNumber;
            cout<<"Enter Amount: ";
            cin >> amount;
            acc = b.Withdraw(accountNumber, amount);
            cout<<"\nAmount Withdrawn\n";
            cout<<acc;
            break;
        case 5:
            cout<<"Enter Account Number: ";
            cin>>accountNumber;
            b.CloseAccount(accountNumber);
            cout<<"\nAccount Closed\n";
            break;
        case 6:
            b.ShowAllAccounts();
            break;
        case 0:
            cout<<"\tThanks For Using Our Banking System\n";
            cout<<"\n\t\tExit Of The Program";
            exit(0);
        default:
            cout<<"\nInvalid Input!";
        }
    } while (choice != 7);
    return 0;
}

Account::Account(string fname, string lname, float balance) {
    NextAccountNumber++;
    accountNumber = NextAccountNumber;
    firstName = fname;
    lastName = lname;
    this->balance = balance;
}

void Account::Deposit(float amount) {
    balance += amount;
}

void Account::Withdraw(float amount) {
    if (balance - amount < MIN_BALANCE)
        throw InsufficientFunds();
    balance -= amount;
}

ostream &operator<<(ostream &os, Account &acc) {
    os<<"First Name: "<<acc.getFirstName()<<endl;
    os<<"Last Name: "<<acc.getLastName()<<endl;
    os<<"Account Number: "<<acc.getAccNo()<<endl;
    os<<"Balance: "<<acc.getBalance()<<endl;
    return os;
}

Account Bank::OpenAccount(string fname, string lname, float balance) {
    Account account(fname, lname, balance);
    accounts.insert({account.getAccNo(), account});
    return account;
}

Account Bank::BalanceEnquiry(long accountNumber) {
    return accounts.at(accountNumber);
}

Account Bank::Deposit(long accountNumber, float amount) {
    accounts.at(accountNumber).Deposit(amount);
    return accounts.at(accountNumber);
}

Account Bank::Withdraw(long accountNumber, float amount) {
    accounts.at(accountNumber).Withdraw(amount);
    return accounts.at(accountNumber);
}

void Bank::CloseAccount(long accountNumber) {
    accounts.erase(accountNumber);
    cout<<"Account Deleted Successfully."<<endl;
}

void Bank::ShowAllAccounts() {
    for (auto &acc : accounts) {
        cout<<"Account "<<acc.first<<endl<<acc.second<<endl;
    }
}
