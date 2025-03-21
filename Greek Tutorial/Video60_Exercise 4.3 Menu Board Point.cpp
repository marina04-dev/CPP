#include <iostream>
#include <cstdlib>
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

class Board {
  public:
    Board(int in_N);
    Board(const Board &ob);
    char get_elem(int i, int j);
    ~Board();
    Board &operator=(const Board &ob);
    void insert_point(Point ob);
    void clear();
    friend ostream &operator<<(ostream &left, const Board &right);
  private:
    int N;
    char **p;
};

int main() {
    int choice;
    Point temp_point(0,0);
    Board b(20);
    int temp_int;
    
    
    while (true) {
        cout<<"Menu"<<endl;
        cout<<"1-Point Insertion"<<endl;
        cout<<"2-Board Printing"<<endl;
        cout<<"3-Clear Board"<<endl;
        cout<<"4-Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        
        switch (choice) {
            case 1:
                cout<<"Enter x dimension: "<<endl;
                cin>>temp_int;
                temp_point.set_x(temp_int);
                cout<<"Enter y dimension: "<<endl;
                cin>>temp_int;
                temp_point.set_y(temp_int);
                b.insert_point(temp_point);
                break;
            case 2:
                cout<<endl<<endl<<b;
                break;
            case 3:
                b.clear();
                cout<<"Board Cleaned!"<<endl;
                break;
            case 4:
                cout<<"Exit";
                exit(0);
            default:
                cout<<"Wrong Input!";
            
        }
    }
    
    return 0;
}

Point::Point(int in_x, int in_y) {
    if (in_x>=0 && in_x<60) {
        x=in_x;
    }
    else {
        cout<<"Wrong Input in x Dimension!"<<endl;
    }
    
    if (in_y>=0 && in_y<60) {
        y=in_y;
    }
    else {
        cout<<"Wrong Input in y Dimension!"<<endl;
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
    cout<<"("<<right.x<<","<<right.y<<")";
    return left;
}

Board::Board(int in_N) {
    N=in_N;
    p = new char *[N];
    if (!p) {
        cout<<"Error Allocating Memory!";
        exit(0);
    }
    
    for (int i=0; i<N; i++) {
        p[i] = new char [N];
        if (!p[i]) {
            cout<<"Error Allocating Memory!";
            exit(0);
        }
    }
    
    for (int j=0; j<N; j++) {
        for (int k=0; k<N; k++) {
            p[j][k]='.';
        }
    }
}

Board::Board(const Board &ob) {
    N=ob.N;
    p = new char *[N];
    if (!p) {
        cout<<"Error Allocating Memory!";
        exit(0);
    }
    
    for (int i=0; i<N; i++) {
        p[i] = new char [N];
        if (!p[i]) {
            cout<<"Error Allocating Memory!";
            exit(0);
        }
    }
    
    for (int j=0; j<N; j++) {
        for (int k=0; k<N; k++) {
            p[j][k]=ob.p[j][k];
        }
    }
    
}

Board &Board::operator=(const Board &ob) {
    if (p!=NULL) {
        for (int i=0; i<N; i++) {
            delete [] p[i];
        }
        delete [] p;
        
        
        N=ob.N;
        p = new char *[N];
        if (!p) {
            cout<<"Error Allocating Memory!";
            exit(0);
        }
        
        for (int i=0; i<N; i++) {
            p[i] = new char [N];
            if (!p[i]) {
                cout<<"Error Allocating Memory!";
                exit(0);
            }
        }
        
        for (int j=0; j<N; j++) {
            for (int k=0; k<N; k++) {
                p[j][k]=ob.p[j][k];
            }
        }
    }
    
    N=ob.N;
    p = new char *[N];
    if (!p) {
        cout<<"Error Allocating Memory!";
        exit(0);
    }
    
    for (int i=0; i<N; i++) {
        p[i] = new char [N];
        if (!p[i]) {
            cout<<"Error Allocating Memory!";
            exit(0);
        }
    }
    
    for (int j=0; j<N; j++) {
        for (int k=0; k<N; k++) {
            p[j][k]=ob.p[j][k];
        }
    }
}

Board::~Board() {
    for (int i=0; i<N; i++) {
        delete [] p[i];
    }
    delete p;
    
}

char Board::get_elem(int i, int j) {
    return p[i][j];
}

ostream &operator<<(ostream &left, const Board &right) {
    int i,j;
    for (i=right.N-1; i>=0; i--) {
        for (j=0; j<right.N; j++) {
            left<<right.p[i][j]<<" ";
        }
        left<<endl;
    }
    return left;
}

void Board::insert_point(Point ob) {
    if (ob.get_x()>=0 && ob.get_x()<N && ob.get_y()>=0 && ob.get_y()<N) {
        p[ob.get_x()][ob.get_y()]='O';
    }
}

void Board::clear() {
    int i,j;
    for (i=0; i<N; i++) {
        for (j=0; j<N; j++) {
            p[i][j]='.';
        }
    }
}
