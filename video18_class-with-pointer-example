// example of a class that has a pointer member
#include <iostream>
using namespace std;

class dummy {
    public:
        dummy();
        ~dummy();
        void set_val(int in_val);
        int get_val();
    private:
        int *p_val;
};

int main() {
    dummy ob;
    ob.set_val(3);
    cout<<endl<<ob.get_val()<<endl;
}

dummy::dummy() {
    p_val = new int;
    if (!p_val) cout<<"Error allocating memory";
    cout<<"Constructing...";
}

dummy::~dummy() {
    delete p_val;
    cout<<"Constructing...";
}

void dummy::set_val(int in_val) {
    *p_val = in_val;
}

int dummy::get_val() {
    return *p_val;
}
