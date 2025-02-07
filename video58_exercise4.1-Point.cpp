#include <iostream>
using namespace std;

class Point {
    public:
        Point(int in_x, int in_y);
        int get_x() const;
        int get_y() const;
        void set_x(int in_x);
        void set_y(int in_y);
        friend ostream &operator<<(ostream &left, const Point &right);
    private:
        int x;
        int y;
};

ostream &operator<<(ostream &left, const Point &right);

int main() {
    Point p(3,5);
    cout<<p;
    return 0;
}

Point::Point(int in_x, int in_y) {
    if (in_x>=0 && in_x<60) {
        x=in_x;
    }
    else {
        cout<<"Wrong Input in x Dimension"<<endl;
        x=0;
    }
    
    if (in_y>=0 && in_y<60) {
        y=in_y;
    }
    else {
        cout<<"Wrong Input in y Dimension"<<endl;
        y=0;
    }
}

int Point::get_x() const {
    return x;
}

int Point::get_y() const {
    return y;
}


void Point::set_x(int in_x) {
    x=in_x;
}


void Point::set_y(int in_y) {
    y=in_y;
}

ostream &operator<<(ostream &left, const Point &right) {
    left<<"("<<right.x<<","<<right.y<<")";
    return left;
}
