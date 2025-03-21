#include <iostream>
using namespace std;


class Point {
    public:
        point();
        point(double in_x, double in_y);
        void set_x(double in_x);
        void set_y(double in_y);
        double get_x() const;
        double get_y() const;
        void print();
    private:
        double x;
        double y;
};

void swap(int &x, int &y);
void swap(double &x, double &y);
void swap(point &x, point &y);

int main() {
    // Ints
    int a=1, b=2;
    
    cout<<"A: "<<a<<" "<<"B: "<<b<<endl;
    
    swap(a,b);
    
    cout<<"A: "<<a<<" "<<"B: "<<b<<endl;
    
    // Doubles
    double c=13.4, d=2.90;
    
    cout<<"C: "<<c<<" "<<"D: "<<d<<endl;
    
    swap(c,d);
    
    cout<<"C: "<<c<<" "<<"D: "<<d<<endl;
    
    // Points
    point z(13.4,5.87), f(2.90,8,45);
    
    z.print()
    f.print();
    swap(z,f);
    
    z.print()
    f.print();
    
    return 0;
}

void swap(int &x, int &y) {
    int temp;
    temp=x;
    x=y;
    y=temp;
}

void swap(double &x, double &y) {
    double temp;
    temp=x;
    x=y;
    y=temp;
}

void swap(point &x, point &y) {
    point temp;
    temp=x;
    x=y;
    y=temp;
}

point::point() {
    x = 0.0;
    y = 0.0;
}

point::point(double in_x, double in_y) {
    x = in_x;
    y = in_y;
}

void point::set_x(double in_x) {
    x = in_x;
}

void point::set_y(double in_y) {
    y = in_y;
}

double point::get_x() const {
    return x;
}

double point::get_y() const {
    return y;
}

void point::print() {
    cout<<"("<<x<<","<<y<<")";
}
