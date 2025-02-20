#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Array {
    public:
        Array(int in_n);
        Array(const Array<T> &ob);
        ~Array();
        int get_n() const;
        T &operator[] (int i);
        Array<T> &operator= (Array<T> &right);
        Array<T> &operator+= (int right);
        template <typename U> friend ostream &operator<<(ostream &left, const Array<U> &ob);
    private:
        T *p;
        int n;
};

int main() {
    int n=10;
    Array<double> pin(n);
    
    for (int i=0; i<n; i++) {
        pin[i]=i*0.1;
    }
    cout<<pin;
    return 0;
}

template <typename T>
Array<T>::Array(int in_n) {
    n = in_n;
    p = new T [n];
    if (!p) {
        cout<<"Error Allocating Memory!";
    }
}

template <typename T>
Array<T>::Array(const Array<T> &ob) {
    n = ob.get_n();
    p = new T [n];
    if (!p) {
        cout<<"Error Allocating Memory!";
    }
}

template <typename T>
Array<T>::~Array() {
    delete [] p;
}

template <typename T>
int Array<T>::get_n() const {
    return n;
}

template <typename T>
T &Array<T>::operator[] (int i) {
    if (i>=0 && i<n) {
        return p[i];
    }
    else {
        cout<<"Error Index Out Of Bounds!";
    }
}

template <typename T>
Array<T> &Array<T>::operator= (Array<T> &right) {
    if (this==&right) return *this;
    n=right.n;
    delete [] p;
    p = new T [n];
    if (!p) cout<<"Error Allocating Memory!";
    
    for (int i=0; i<n; i++) {
        p[i]=right[i];
    }
    return *this;
}

template <typename T>
Array<T> &Array<T>::operator+= (int right) {
    int newn=n+right;
    int *newp;
    int i;
    
    if (right>0) {
        newp = new T [newn];
        if (!newp) cout<<"Error Allocating Memory!";
        
        for (i=0; i<n; i++) {
            newp[i]=p[i];
        }
        for (i=n; i<newn; i++) {
            newp[i]=0;
        }
        delete [] p;
        n=newn;
        p=newp;
    }
    else {
        cout<<"Error Index Out Of Bounds!";
    }
}

template <typename T>
ostream &operator<<(ostream &left, const Array<T> &ob) {
    int i;
    left<<"[";
    for (i=0; i<ob.n-1; i++) {
        cout<<ob.p[i]<<" ";
    }
    left<<ob.p[ob.n-1];
    left<<"]";
    return left;
}
