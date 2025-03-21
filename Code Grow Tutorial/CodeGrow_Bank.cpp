#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

void showBalance(double balance);
double deposit();
double withdraw(double balance);

int main()
{
    double balance=1324.56;
    int choice=0;
    
    do {
        cout<<"*****************************************"<<endl;
        cout<<"***********Enter your Choice:************"<<endl;
        cout<<"*****************************************"<<endl;
        cout<<"1. Show Balance"<<endl;
        cout<<"2. Deposit Money"<<endl;
        cout<<"3. Withdraw Money"<<endl;
        cout<<"4. Exit"<<endl;
        cin>>choice;
        cin.clear();
        fflush(stdin);
        
        switch (choice) {
            case 1:
                showBalance(balance);
                break;
            case 2:
                balance += deposit();
                cout<<"New Balance: "<<balance<<endl;
                break;
            case 3:
                balance -= withdraw(balance);
                cout<<"New Balance: "<<balance<<endl;
                break;
            case 4:
                cout<<endl<<"Exit";
                break;
            default:
                cout<<"Wrong Input! Enter a number between 1 and 4"<<endl;
                break;
        }
    } while (choice != 4);
    return 0;
}

void showBalance(double balance) {
    cout<<"Balance: "<<balance<<std::setprecision(2)<<std::fixed<<"€"<<endl;
}

double deposit() {
    double amount = 0.0;
    cout<<"Enter amount to be deposited: "<<endl;
    cin>>amount;
    
    if (amount>0) {
        return amount;
    }
    else {
        cout<<"That's not a valid amount"<<endl;
    }
    return 0;
}

double withdraw(double balance) {
    double amount = 0.0;
    cout<<"Enter amount to be withdrawn: "<<endl;
    cin>>amount;
    
    if (amount>balance) {
        cout<<"Not Enough Money In the Account"<<endl;
        return 0;
    }
    else if (amount<0) {
        cout<<"That's not a valid amount"<<endl;
        return 0;
    }
    else if (amount>=0 && amount<=balance) {
        return amount;
    }
    else {
        cout<<"Wrong Input! Enter a valid amount!"<<endl;
        return 0;
    }
}
