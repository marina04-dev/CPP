#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
using namespace std;

class Wizard {
    public:
        Wizard(int in_age, string in_beard, int in_mana, int in_health);
        int get_health() const;
        int fireball();
        int lightning();
        void wait();
        bool check_dead();
        int attack();
        Wizard &operator+=(int add_health);
        Wizard &operator-=(int sub_health);
    private:
        int age;
        string beard;
        int mana;
        int health;
};

class Humanoid {
    public:
        Humanoid();
        int get_health() const;
        int attack();
        bool check_dead();
        Humanoid &operator-=(int sub_health);
    private:
        int health;
};

int main() {
    
    Wizard Gandalf(2019, "grey", 100, 100);
    int damage;
    Humanoid h;
    int r;
    
    /* Game Scenario */
    srand(time(0));
    r = 1;
    while(1) {
        cout<<endl<<"=============================";
        cout<<endl<<"Round "<<r<<endl;
        
        // Wizard Plays
        damage = Gandalf.attack();
        h-=damage;
        
        if (rand()%2==0) { // lightning
            damage = Gandalf.lightning();
            h-=damage;
        }
        else { // fireball
            damage = Gandalf.fireball();
            h-=damage;
        }
        
        /* Check if Humanoid is Dead */
        if (h.check_dead()) {
            cout<<endl<<"Humanoid is Dead";
            break;
        }
        
        /* Humanoid Plays */
        damage=h.attack();
        Gandalf-=damage;
        
        // Check if Wizard is Dead 
        if (Gandalf.check_dead()) {
            cout<<endl<<"Wizard is Dead!";
            break;
        }
        
        // Health Printing 
        cout<<endl<<"Wizard's Health: "<<Gandalf.get_health();
        cout<<endl<<"Humanoid's Health: "<<h.get_health();
        
        // Round Increase
        Gandalf.wait();
        r++;
    }
    return 0;
}

Wizard::Wizard(int in_age, string in_beard, int in_mana, int in_health) {
    age = in_age;
    beard = in_beard;
    mana = in_mana;
    health = in_health;
}

int Wizard::get_health() const {
    return health;
}

int Wizard::lightning() {
    if (mana >= 30) {
        mana -= 30;
        cout<<endl<<"Lightning! (mana:"<<mana<<")";
        return 10+rand()%21;
    }
    else {
        cout<<endl<<"Lightning Effort...Not enough mana";
        return 0;
    }
}

int Wizard::fireball() {
    if (mana >= 90) {
        mana -= 90;
        cout<<endl<<"Fireball! (mana:"<<mana<<")";
        return 50+rand()%21;
    }
    else {
        cout<<endl<<"Fireball Effort...Not enough mana";
        return 0;
    }
}

void Wizard::wait() {
    if (mana<=90) {
        mana += 10;
    }
    cout<<endl<<"Wait...(mana:"<<mana<<")";
}

bool Wizard::check_dead() {
    if (health<=0) {
        return true;
    }
    return false;
}

int Wizard::attack() {
    return 20+rand()%11;
}

Wizard &Wizard::operator+=(int add_health) {
    health += add_health;
    if (health>100) {
       health=100;
    }
    return *this;
}


Wizard &Wizard::operator-=(int sub_health) {
    health -= sub_health;
    if (health<=0) {
       cout<<endl<<"Wizard Dead!";
    } 
}

Humanoid::Humanoid() {
    health=100;
}

int Humanoid::get_health() const {
    return health;
}

int Humanoid::attack() {
    return 1+rand()%5;
}

bool Humanoid::check_dead() {
    if (health<=0) {
        return true;
    }
    return false;
}

Humanoid &Humanoid::operator-=(int sub_health) {
    health -= sub_health;
    if (health<=0) {
       cout<<endl<<"Humanoid Dead!";
    }
}
