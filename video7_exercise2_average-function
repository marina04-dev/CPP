#include <iostream>

using namespace std;

double average(int a, int b);
double average(double a, double b);

int main() {
    int int_a,int_b;
    double double_a, double_b;
    int in;
    
    cout<<"Please enter 1 for Integers or 2 for Doubles: "<<"\n";
    cin>>in;
    
    if (in==1) {
        cout<<"Please enter the 1st integer: "<<"\n";
        cin>>int_a;
        cout<<"Please enter the 2nd integer: "<<"\n";
        cin>>int_b;
        cout<<"The average is: "<<average(int_a,int_b);
    }
    else if (in==2) {
        cout<<"Please enter the 1st double: "<<"\n";
        cin>>double_a;
        cout<<"Please enter the 2nd double: "<<"\n";
        cin>>double_b;
        cout<<"The average is: "<<average(double_a,double_b);
    }
    else {
        cout<<"Wrong Input!";
    }
    return 0;
}

double average(int a, int b) {
    return (a+b)/2.0;
}

double average(double a, double b) {
    return (a+b)/2;
}
