#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
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
        void serve(int in_customers, Barista &b);
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
    int clients, waiter_to_serve, barista_to_serve;
    Owner *o = new Owner("Jack", 2300);
    Waiter *w1 = new Waiter("Mary", 800);
    Waiter *w2 = new Waiter("Jason", 900);
    Barista *b = new Barista("Freddy", 1000);
    Waiter *waiters[3] = {o,w1,w2};
    Barista *baristas[2] = {o,b};
    
    srand(time(NULL));
    for (int i=0; i<100; i++) {
        clients = 1+rand()%5;
        waiter_to_serve = rand()%3;
        barista_to_serve = rand()%2;
        
        // SOS: Because waiter is pointer I use -> for method serve and not dot
        // SOS: Also for baristas i have to put the * before in order to dereference it and make it an object
        waiters[waiter_to_serve]->serve(clients, *baristas[barista_to_serve]);
    }
    
    for (int i=0; i<3; i++) {
        cout<<*waiters[i];
    }
    
    delete o;
    delete w1;
    delete w2;
    delete b;
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

void Waiter::serve(int in_customers, Barista &b) {
    b.prepare();
    served_cust+=in_customers;
}

ostream &operator<<(ostream &left, Waiter &right) {
    left<<"Name: "<<right.name<<endl<<"Salary: "<<right.salary<<endl<<"Customers Served: "<<right.served_cust<<endl<<endl;
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
