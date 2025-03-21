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
        wizard &operator+=(int add_health);
        wizard &operator-=(int sub_health);
    private:
        int age;
        char beard[80];
        int mana;
        int health;
};

int main() {
    char str[80]="grey";
    wizard gandalf(2019, str, 100, 100);
    int damage;
    srand(time(0));
    
    damage = gandalf.lightning();
    cout<<endl<<"Damage (lightning)="<<damage;
    gandalf.wait();
    damage = gandalf.fireball();
    cout<<endl<<"Damage (fireball)="<<damage<<endl;
    gandalf.wait();
    gandalf.wait();
    damage = gandalf.lightning();
    cout<<endl<<"Damage (lightning)="<<damage;
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
