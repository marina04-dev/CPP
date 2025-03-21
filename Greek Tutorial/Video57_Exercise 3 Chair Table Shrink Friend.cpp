#include <iostream>
#include "STRING.h"
using namespace std;
class table; // forward declaration

class chair {
    public:
        chair(STRING in_color, int in_height);
        friend ostream &operator<<(ostream &left, const chair &right);
        friend void shrink(table &t, chair &c);
    private:
        STRING color;
        int height;
};

class table {
    public:
        table(STRING in_color, int in_height, int in_width);
        friend ostream &operator<<(ostream &left, const table &right);
        friend void shrink(table &t, chair &c);
    private:
        STRING color;
        int height;
        int width;
};

void shrink(table &t, chair &c);
ostream &operator<<(ostream &left, const chair &right);
ostream &operator<<(ostream &left, const table &right);

int main() {
    chair c("blue", 150);
    table t("red", 160, 200);
    cout<<c<<endl;
    cout<<t<<endl;
    shrink(t,c);
    cout<<c<<endl;
    cout<<t<<endl;
    
    return 0;
}

chair::chair(STRING in_color, int in_height) {
    color = in_color;
    height = in_height;
}

ostream &operator<<(ostream &left, const chair &right) {
    left<<"Chair's color: "<<right.color<<endl<<"Chair's height: "<<right.height;
    return left;
}

table::table(STRING in_color, int in_height, int in_width) {
    color = in_color;
    height = in_height;
    width = in_width;
}

ostream &operator<<(ostream &left, const table &right) {
    left<<"Table's color: "<<right.color<<endl<<"Table's height: "<<right.height<<endl<<"Table's width: "<<right.width;
    return left;
}

void shrink(table &t, chair &c) {
    t.height = 0.9 * t.height;
    t.width = 0.9 * t.width;
    c.height = 0.9 * c.height;
}
