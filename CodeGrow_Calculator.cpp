#include <iostream>
using namespace std;


int main()
{
    char op;
    double num1;
    double num2;
    
    
    cout<<"*************** CALCULATOR ******************"<<endl;
    cout<<"Enter the first number: "<<endl;
    cin>>num1;
    
    cout<<"Enter the second number: "<<endl;
    cin>>num2;
    
    cout<<"Enter the calculation mark: "<<endl;
    cin>>op;
    
    switch (op) {
        case '+':
            cout<<"Result: "<<num1+num2<<endl;
            break;
        case '/':
            cout<<"Result: "<<num1/num2<<endl;
            break;
        case '*':
            cout<<"Result: "<<num1*num2<<endl;
            break;
        case '-':
            cout<<"Result: "<<num1-num2<<endl;
            break;
        default:
            cout<<"Wrong Input!"<<endl;
            break;
    }

    return 0;
}
