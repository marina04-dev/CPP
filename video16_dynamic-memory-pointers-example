#include <iostream>
using namespace std;

int main() {
    int x; // variable that stores static space 
    int *p; // pointer to integer
    
    // Dynamic memory allocation
    p=new int;
    
    // Check if memory allocation is valid
    if (!p) cout <<"Error allocating memory";
    
    // Values initialization
    x=1;
    *p=5;
    
    
    // Printings
    cout<<"x = "<<x<<" (address: "<<&x<<")"<<endl;
    cout<<"p = "<<*p<<" (address: "<<p<<")"<<endl;
    
    delete p; // memory freedom
    return 0;
    
}
