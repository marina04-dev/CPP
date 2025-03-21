#include <iostream>
#include <string>
using namespace std;

template <typename T>
void myswap(T &a, T &b);

int main() {
    int a=2, b=3;
    cout<<"a = "<<a<<endl<<"b = "<<b<<endl<<endl;
    myswap<int>(a,b);
    cout<<"After Swap"<<endl;
    cout<<"a = "<<a<<endl<<"b = "<<b<<endl<<endl;
    return 0;
}

template <typename T>
void myswap(T &a, T &b) {
    T temp;
    temp=a;
    a=b;
    b=temp;
}
