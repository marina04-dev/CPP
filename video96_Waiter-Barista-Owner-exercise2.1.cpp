#include <iostream>
#include <string>
using namespace std;

class Person {
    public:
        Person();
        Person(string in_name, double in_salary);
        friend ostream &operator<<(ostream &left, Person &right);
    protected:
        string name;
        double salary;
};

class Barista: virtual public Person {
    public:
       Barista();
        Barista(string in_name, double in_salary);
        void prepare();
        friend ostream &operator<<(ostream &left, Barista &right);
};

class Waiter: virtual public Person {
    public:
        Waiter();
        Waiter(string in_name, double in_salary);
        void serve(int customers, Barista &b);
        friend ostream &operator<<(ostream &left, Waiter &right);
    protected:
        int served_cust;
};


class Owner: public Waiter, public Barista {
  public:
    Owner(string in_name, double in_salary);
    friend ostream &operator<<(ostream &left, Owner &right);
};

int main() {
    return 0;
}

Person::Person() {}

Person::Person(string in_name, double in_salary) {
    name = in_name;
    salary = in_salary;
}

ostream &operator<<(ostream &left, Person &right) {
    left<<"Name: "<<right.name<<endl<<"Salary: "<<right.salary<<endl<<endl;
    return left;
}

Waiter::Waiter() {
    served_cust = 0;
}

Waiter::Waiter(string in_name, double in_salary): Person(in_name, in_salary) {
    served_cust = 0;
}

void Waiter::serve(int customers, Barista &b) {
    b.prepare();
    customers+=customers;
}

ostream &operator<<(ostream &left, Waiter &right) {
    left<<"Name: "<<right.name<<endl<<"Salary: "<<right.salary<<"Customers Served: "<<right.served_cust<<endl<<endl;
    return left;
}


Barista::Barista() {}

Barista::Barista(string in_name, double in_salary): Person(in_name, in_salary) {}

void Barista::prepare() {
    cout<<"Barista is Preparing..."<<endl;
}

ostream &operator<<(ostream &left, Barista &right) {
    left<<"Name: "<<right.name<<endl<<"Salary: "<<right.salary<<endl<<endl;
    return left;
}

Owner::Owner(string in_name, double in_salary): Person(in_name, in_salary) {}

ostream &operator<<(ostream &left, Owner &right) {
    left<<"Name: "<<right.name<<endl<<"Salary: "<<right.salary<<endl<<endl;
    return left;
}
