// object with constructor and destructor : pointers
#include <iostream>
using namespace std;

class dummy {
    public:
        dummy(int in_x);
        ~dummy();
    private:
        int x;
};

int main() {
    dummy *p = NULL; // object pointer
    p = new dummy(5);  // memory allocation
    
    // check for valid memory allocation
    if (!p) cout<<"Error allocating memory";
    
    delete p; // destructing
    return 0;
    
}

dummy::dummy(int in_x) {
    x = in_x;
    cout<<"Constructing..."<<endl;
}

dummy::~dummy() {
    cout<<"Destructing..."<<endl;
}
