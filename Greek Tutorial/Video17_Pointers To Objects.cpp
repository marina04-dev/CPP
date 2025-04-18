#include <iostream>
using namespace std;

class dummy {
    public:
        int x;
};

int main() {
    dummy *p = NULL; // object pointer
    p = new dummy;  // memory allocation
    
    // check for valid memory allocation
    if (!p) cout<<"Error allocating memory";
    
    p->x=5;  // values initialization
    
    cout<<"p->x= "<<p->x<<endl; // printings
    
    delete p; // memory freedom
    return 0;
    
}



// 2nd way of writting: (*p).x

#include <iostream>
using namespace std;

class dummy {
    public:
        int x;
};

int main() {
    dummy *p = NULL; // object pointer
    p = new dummy;  // memory allocation
    
    // check for valid memory allocation
    if (!p) cout<<"Error allocating memory";
    
    (*p).x=5;  // values initialization
    
    cout<<"p->x= "<<(*p).x<<endl; // printings
    
    delete p; // memory freedom
    return 0;
    
}
