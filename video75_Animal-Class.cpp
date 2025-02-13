#include <iostream>
using namespace std;

class Animal {
    public:
        Animal();
        Animal(int in_weight, int in_height, int in_mood);
        ~Animal();
        void set_weight(int in_weight);
        void set_height(int in_height);
        void set_mood(int in_mood);
        int get_weight() const;
        int get_height() const;
        int get_mood() const;
        void eat();
        void drink();
        void sleep();
        friend ostream &operator<<(ostream &left, const Animal &right);
    private:
        int weight;
        int height;
        int mood;
};


int main() {
    Animal an(21,67,4);
    cout<<an;
    return 0;
}

Animal::Animal() {
    weight = 0;
    height = 0;
    mood = 0;
    cout<<"Constructing...Without Arguments..."<<endl;
}

Animal::Animal(int in_weight, int in_height, int in_mood) {
    weight = in_weight;
    height = in_height;
    mood = in_mood;
    cout<<"Constructing...With Arguments..."<<endl;
}

Animal::~Animal() {
    cout<<"Destructing..."<<endl;
}

void Animal::set_weight(int in_weight) {
    weight = in_weight;
}

void Animal::set_height(int in_height) {
    height = in_height;
}

void Animal::set_mood(int in_mood) {
    mood = in_mood;
}

int Animal::get_weight() const {
    return weight;
}

int Animal::get_height() const {
    return height;
}

int Animal::get_mood() const {
    return mood;
}

void Animal::eat() {
    if (mood<10) {
        cout<<"Animal is eating..."<<endl;
        mood++;
    }
    else if (mood==10){
        cout<<"Animal is Completely Happy!"<<endl;
        mood=10;
    }
}

void Animal::drink() {
    if (mood<10) {
        cout<<"Animal is drinking..."<<endl;
        mood++;
    }
    else if (mood==10){
        cout<<"Animal is Completely Happy!"<<endl;
        mood=10;
    }
}

void Animal::sleep() {
    if (mood<10) {
        cout<<"Animal is sleeping..."<<endl;
        mood++;
    }
    else if (mood==10){
        cout<<"Animal is Completely Happy!"<<endl;
        mood=10;
    }
}

ostream &operator<<(ostream &left, const Animal &right) {
    left<<"Animal's Weight: "<<right.weight<<"kg"<<endl<<"Animal's Height: "<<right.height<<"cm"<<endl<<"Animal's Mood: "<<right.mood<<endl;
    return left;
}
