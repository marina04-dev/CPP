#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

class wizard {
    public:
        wizard(int in_age, char *in_beard, int in_mana, int in_health);
        int fireball();
        int lightning();
        void wait();
        bool check_dead();
        int get_health() const;
        wizard &operator+=(int add_health);
        wizard &operator-=(int sub_health);
    private:
        int age;
        char beard[80];
        int mana;
        int health;
};

class humanoid {
    public:
        humanoid();
        bool check_dead();
        humanoid &operator-=(int sub_health);
        int attack();
        int get_health() const;
    private:
        int health;
};


int main() {
    char str[80]="grey";
    wizard gandalf(2019, str, 100, 100);
    int damage;
    humanoid h;
    srand(time(0));
    int r;
    r=1;
    while(1) {
        cout<<"Round "<<r<<endl;
        
        // Wizard Plays
        if (rand()%2==0) { // lightning
            damage = gandalf.lightning();
            h-=damage;
        }
        else { // fireball
            damage = gandalf.fireball();
            h-=damage;
        }
        
        // Check if Humanoid is Dead 
        if (h.check_dead()) {
            cout<<endl<<"Humanoid is Dead!";
            break;
        }
        
        // Humanoid Plays
        damage=h.attack();
        gandalf-=damage;
        
        // Check if Wizard is Dead 
        if (gandalf.check_dead()) {
            cout<<endl<<"Wizard is Dead!";
            break;
        }
        
        // Health Printing
        cout<<endl<<"Wizard (health): "<<gandalf.get_health();
        cout<<endl<<"Humanoid (health): "<<h.get_health();
        
        // Add Round
        gandalf.wait();
        r++;
    }
    return 0;
}

wizard::wizard(int in_age, char *in_beard, int in_mana, int in_health) {
    age = in_age;
    strcpy(beard, in_beard);
    mana = in_mana;
    health = in_health;
}

int wizard::fireball() {
    if (mana >= 90) {
        mana -= 90;
        cout<<endl<<"Fireball! (mana: "<<mana<<")";
        return 50+rand()%21;
    }
    else {
        cout<<endl<<"Fireball Effort (not enough mana)";
        return 0;
    }
}

int wizard::lightning() {
    if (mana >= 30) {
        mana -= 30;
        cout<<endl<<"Lightning! (mana: "<<mana<<")";
        return 10+rand()%21;
    }
    else {
        cout<<endl<<"Lightning Effort (not enough mana)";
        return 0;
    }
}

void wizard::wait() {
    if (mana <= 90) {
        mana += 10;
    }
    cout<<endl<<"Wait... (mana: "<<mana<<")";
}

wizard &wizard::operator+=(int add_health) {
    health+=add_health;
    if (health>100) {
        health=100;
    }
    return *this;
}

wizard &wizard::operator-=(int sub_health) {
    health-=sub_health;
    if (health<=0) {
        cout<<"Wizard is Dead!";
    }
}

bool wizard::check_dead() {
    if (health<=0) {
        return true;
    }
    return false;
}

int wizard::get_health() const {
    return health;
}

humanoid::humanoid() {
    health=100;
}

humanoid &humanoid::operator-=(int sub_health) {
    health-=sub_health;
    if (health<=0) {
        cout<<"Humanoid is Dead!";
    }
}

int humanoid::attack() {
    return 1+rand()%5;
}

bool humanoid::check_dead() {
    if (health<=0) {
        return true;
    }
    return false;
}

int humanoid::get_health() const {
    return health;
}
