#include <iostream>
#include <string>
using namespace std;

class Person {
    public:
        Person(string in_name);
    protected:
        string name;
};

class King: public Person {
    public:
        King(string in_name, string in_realm);
        ~King();
        void set_realm(string in_realm);
        void rule();
    protected:
        string realm;
};

class Philosopher: public Person {
    public:
        Philosopher(string in_name, string in_philosophy);
        ~Philosopher();
        void set_philosophy(string in_philosophy);
        void think();
    protected:
        string philosophy;
};

class KingPhilosopher: public Person, public King, public Philosopher {
    public:
        KingPhilosopher(string in_name, string in_realm, string in_philosophy);
        ~KingPhilosopher();
        void routine();
        friend ostream &operator<<(ostream &left, KingPhilosopher &right);
};

int main() {
    KingPhilosopher Marcus_Avrilius("Marcus Aurelius","Roman Empire", "Stoic");
    Marcus_Avrilius.routine();
    return 0;
}

Person::Person(string in_name) {
    name = in_name;
}

King::King(string in_name, string in_realm): Person(in_name) {
    realm = in_realm;
    cout<<endl<<"Constructing King";
}
King::~King() {
    cout<<endl<<"Destructing King";
}


void King::set_realm(string in_realm) {
    realm = in_realm;
}

void King::rule() {
    cout<<endl<<"Now I Rule";
}

Philosopher::Philosopher(string in_name, string in_philosophy): Person(in_name) {
    philosophy = in_philosophy;
    cout<<endl<<"Constructing Philosopher";
}

Philosopher::~Philosopher() {
    cout<<endl<<"Destructing Philosopher";
}


void Philosopher::set_philosophy(string in_philosophy) {
    philosophy = in_philosophy;
}

void Philosopher::think() {
    cout<<endl<<"Now I Think";
}

KingPhilosopher::KingPhilosopher(string in_name, string in_realm, string in_philosophy):
Person(in_name),King(in_name, in_realm),Philosopher(in_name, in_philosophy) {
    cout<<endl<<"Constructing Philosopher King";
}

KingPhilosopher::~KingPhilosopher() {
    cout<<endl<<"Destructing Philosopher King";
}

void KingPhilosopher::routine() {
    think();
    rule();
    think();
}

ostream &operator<<(ostream &left, KingPhilosopher &right) {
    left<<right.name<<endl;
    left<<"Ruling: "<<right.realm<<endl;
    left<<"Using: "<<right.philosophy<<" philosophy"<<endl;
}
