// Overloading metathematic Single seater Operators 
#include <iostream>
using namespace std;

class complex {
    public:
        complex();
        complex(double in_real, double in_imag);
        void set_real(double in_real);
        void set_imag(double in_imag);
        double get_real() const;
        double get_imag() const;
        complex operator++ (int right);
        complex operator-- (int right);
    private:
        double real;
        double imag;
};

int main() {
    complex a(1.0,1.0);
    complex c;
    c = a++;
    cout<<c.get_real()<<" "<<c.get_imag()<<endl;
    
    complex f;
    f = a--;
    cout<<f.get_real()<<" "<<f.get_imag();
    return 0;
}

complex::complex() {
    real=0.0;
    imag=0.0;
}

complex::complex(double in_real, double in_imag) {
    real = in_real;
    imag = in_imag;
}

void complex::set_real(double in_real) {
    real = in_real;
}

void complex::set_imag(double in_imag) {
    imag = in_imag;
}

double complex::get_real() const {
    return real;
}

double complex::get_imag() const {
    return imag;
}

complex complex::operator++ (int right) {
    complex result = *this;
    this->real++;
    this->imag++;
    return result;
}

complex complex::operator-- (int right) {
    complex result = *this;
    this->real--;
    this->imag--;
    return result;
}
