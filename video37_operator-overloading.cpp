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
        complex operator+ (const complex &right);
        complex operator- (const complex &right);
        complex operator* (const complex &right);
        complex operator/ (const complex &right);
    private:
        double real;
        double imag;
};

int main() {
    complex a(1.0,1.0);
    complex b(2.0,3.0);
    complex c;
    c = a+b;
    cout<<c.get_real()<<" "<<c.get_imag();
    
    complex f;
    f = a-b;
    cout<<f.get_real()<<" "<<f.get_imag();
    
    complex e;
    e = a*b;
    cout<<e.get_real()<<" "<<e.get_imag();
    
    complex d;
    d = a/b;
    cout<<d.get_real()<<" "<<d.get_imag();
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

complex complex::operator+ (const complex &right) {
    complex result;
    result.real = real+right.real;
    result.imag = imag+right.imag;
    return result;
}

complex complex::operator- (const complex &right) {
    complex result;
    result.real = real-right.real;
    result.imag = imag-right.imag;
    return result;
}

complex complex::operator* (const complex &right) {
    complex result;
    result.real = real*right.real;
    result.imag = imag*right.imag;
    return result;
}

complex complex::operator/ (const complex &right) {
    complex result;
    result.real = real/right.real;
    result.imag = imag/right.imag;
    return result;
}
