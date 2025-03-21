#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class demigorgon {
    public:
        demigorgon();
        int attack();
    private:
        int weight;
        int height;
        int health;
};

class demidog {
    public:
        demidog();
        int attack();
    private:
        int health;
};

class hive {
    public:
        hive(bool in_demigorgon);
        int attack();
    private:
        demigorgon *demi_ptr;
        demidog *array_demidogs;
        int n_demidogs;
};

int main() {
    hive h(true);
    int damage;
    damage = h.attack();
    cout<<"Total damage: "<<damage;
    return 0;
}

demigorgon::demigorgon() {
    weight = 500;
    height = 5;
    health = 10000;
}

int demigorgon::attack() {
    srand(time(0));
    return 300+rand()%(200-0+1);
}

demidog::demidog() {
    health = 100;
}

int demidog::attack() {
    return 10+rand()%(20-0+1);
}

hive::hive(bool in_demigorgon) {
    if (in_demigorgon) {
        demi_ptr = new demigorgon;
        if (!demi_ptr) {
            cout<<"Error Allocating Memory!";
        }
    }
    else {
        demi_ptr = NULL;
    }
    
    n_demidogs = 10+rand()%41;
    array_demidogs = new demidog [n_demidogs];
    if (!array_demidogs) {
        cout<<"Error Allocating Memory!";
    }
}

int hive::attack() {
    int damage;
    int i;
    int sum=0;
    if (demi_ptr!=NULL) {
        damage = demi_ptr->attack();
        sum+=damage;
        cout<<"Demigorgon attacks! (damage: "<<damage<<")"<<endl;
    }
    
    for (i=0; i<n_demidogs; i++) {
        damage = array_demidogs[i].attack();
        sum+=damage;
        cout<<"Demidog "<<i<<" attacks! (damage: "<<damage<<")"<<endl;
    }
    return sum;
}

