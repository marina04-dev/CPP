#include <iostream>
#include <string>
using namespace std;

class King {
    public:
        King(string in_realm);
        ~King();
        void set_realm(string in_realm);
        void rule();
    private:
        string realm;
};

class Philosopher {
    public:
        Philosopher(string in_philosophy);
        ~Philosopher();
        void set_philosophy(string in_philosophy);
        void think();
    private:
        string philosophy;
};

class KingPhilosopher: public King, public Philosopher {
    public:
        KingPhilosopher(string in_realm, string in_philosophy);
        ~KingPhilosopher();
        void routine();
};

int main() {
    KingPhilosopher Marcus_Avrilius("Roman Empire", "Stoic");
    Marcus_Avrilius.routine();
    return 0;
}

King::King(string in_realm) {
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

Philosopher::Philosopher(string in_philosophy) {
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

KingPhilosopher::KingPhilosopher(string in_realm, string in_philosophy):
King(in_realm),Philosopher(in_philosophy) {
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
