#include <iostream>
using namespace std;

#define N 3

class grades {
    public:
        grades();
        int set_i(int pos,int val);
        int get_i(int pos) const;
    private:
        int array[N];
};

int main() {
    grades my_grades;
    
    /* Data Insertion */
    my_grades.set_i(0,5);
    my_grades.set_i(1,8);
    my_grades.set_i(2,7);
    
    /* Data Printing */
    for (int i=0; i<N; i++) {
        cout<<my_grades.get_i(i)<<endl;
    }
    return 0;
}

grades::grades() {
    for (int i=0; i<N; i++) {
        array[i]=0;
    }
}

int grades::set_i(int pos, int val) {
    if (pos>=0 && pos<N) {
        array[pos]=val;
    }
    else {
        cout<<"Out of Bounds!";
    }
}

int grades::get_i(int pos) const {
    if (pos>=0 && pos<N) {
        return array[pos];
    }
    else {
        cout<<"Out of Bounds!";
    }
    return 0;
}
