#include <iostream>
#include <string>
using namespace std;

class King {
    public:
        void set_realm(string in_realm);
        void rule();
    private:
        string realm;
};

class Philosopher {
    public:
        void set_philosophy(string in_philosophy);
        void think();
    private:
        string philosophy;
};

class KingPhilosopher: public King, public Philosopher {
    public:
        void routine();
};

int main() {
    KingPhilosopher Marcus_Avrilius;
    Marcus_Avrilius.set_realm("Roman Empire");
    Marcus_Avrilius.set_philosophy("Stoic");
    Marcus_Avrilius.routine();
    return 0;
}

void King::set_realm(string in_realm) {
    realm = in_realm;
}

void King::rule() {
    cout<<endl<<"Now I Rule";
}

void Philosopher::set_philosophy(string in_philosophy) {
    philosophy = in_philosophy;
}

void Philosopher::think() {
    cout<<endl<<"Now I Think";
}

void KingPhilosopher::routine() {
    think();
    rule();
    think();
}
