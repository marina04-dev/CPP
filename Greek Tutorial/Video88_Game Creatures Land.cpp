#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

class Card {
  public:
    Card(string in_name, string in_color, string in_uniq);
    virtual void print(ostream &left);
    friend ostream &operator<<(ostream &left, Card &right);
  protected:
    string name;
    string color;
    string uniq;
};

class Creature: public Card {
  public:
    Creature(string in_name, string in_color, string in_uniq, int in_attack, int in_defence, string in_kind);
    void print(ostream &left);
    friend ostream &operator<<(ostream &left, Creature &right);
  private:
    int attack;
    int defence;
    string kind;
};

class Land: public Card {
  public:
    Land(string in_name, string in_color, string in_uniq, int in_mana, string in_desc, bool in_tap);
    void print(ostream &left);
    friend ostream &operator<<(ostream &left, Land &right);
  private:
    int mana;
    string desc;
    bool tap;
};

class Pool {
  public:
    Pool();
    ~Pool();
    Card *pick_random();
  private:
    Card *cards[300];
    int nCards;
};

class Hand {
  public:
    Hand(Pool &p);
    void pick_card(Pool &p,int i);
    void fill_hand(Pool &p);
    friend ostream &operator<<(ostream &left, Hand &right);
  private:
    Card *cards[10];
    int Ncards;
};

int main() 
{
  srand(time(NULL));
  Pool p;
  Hand h(p);
  cout<<h;
  return 0;  
}

Card::Card(string in_name, string in_color, string in_uniq) {
  name = in_name;
  if (in_color == "blue" || in_color == "green" || in_color == "red" || in_color == "white" || in_color == "black") {
    color = in_color;
  }
  if (in_uniq == "common" || in_uniq == "uncommon" || in_uniq == "rare") {
    uniq = in_uniq;
  }
}

void Card::print(ostream &left) {
  left<<"("<<name<<", "<<color<<", "<<uniq<<")"<<endl;
}

ostream &operator<<(ostream &left, Card &right) {
  right.print(left);
  return left;
}

Creature::Creature(string in_name, string in_color, string in_uniq, int in_attack, int in_defence, string in_kind): Card(in_name, in_color, in_uniq) {
  attack = in_attack;
  defence = in_defence;
  kind = in_kind;
}

void Creature::print(ostream &left) {
  left<<"Card's Name: "<<right.name<<" ,"<<"Card's Color: "<<right.color<<" ,"<<"Card's Unique: "<<right.uniq<<endl;
  left<<"Creature's Attack Power: "<<right.attack<<" ,"<<" Creature's Defence Power: "<<right.defence<<" ,"<<" Creature's Kind: "<<right.kind<<endl;
}

ostream &operator<<(ostream &left, Creature &right) {
  right.print(left);
  return left;
}



Land::Land(string in_name, string in_color, string in_uniq, int in_mana, string in_desc, bool in_tap): Card(in_name, in_color, in_uniq) {
  if (in_mana == 1 || in_mana == 2) {
    mana = in_mana;
  }
  desc = in_desc;
  tap = in_tap;
}

void Land::print(ostream &left) {
  left<<"Card's Name: "<<right.name<<" ,"<<"Card's Color: "<<right.color<<" ,"<<"Card's Unique: "<<right.uniq<<endl;
  left<<"Land's Mana: "<<right.mana<<" ,"<<" Land's Description: "<<right.desc<<" ,"<<" Land's Tap: "<<right.tap<<endl;
}

ostream &operator<<(ostream &left, Land &right) {
  right.print(left);
  return left;
}

Pool::Pool() {
  cards[0]=new Creature("Rune - Scarred Demon","black","rare",6,6,"Demon");
  cards[1]=new Creature("Akroan Crusader","red","common",1,1,"Human Soldier");
  cards[2]=new Land("Plains","white","common", 1, "Basic Land - Plains", true);
  cards[3]=new Land("Swamp","black","uncommon", 1, "Basic Land - Swamp", false);
  cards[4]=new Land("Forest","green","common", 1, "Basic Land - Forest", true);
  cards[5]=new Creature("Aegis Angel","white","rare",5,5,"Angel");
  cards[6]=new Creature("Angler Turtle","blue","rare",5,7,"Turtle");
  cards[7]=new Creature("Harbinger of Night","black","uncommon",2,3,"Summon Spirit");
  cards[8]=new Creature("Ghalta, Primal Hunger","green","rare",12,12,"Legendary Creature-Elder Dinosaur");
  cards[9]=new Creature("Skarrgan Hellkite","red","common",4,4,"Dragon");
  cards[10]=new Creature("Spawn of Mayhem","black","common",4,4,"Demon");
  nCards = 11;
}

Pool::~Pool() {
  int i;
  for (i=0; i<nCards; i++) {
    delete cards[i];
  }
}

Card *Pool::pick_random() {
  return cards[rand()%nCards];
}

Hand::Hand(Pool &p) {
  fill_hand(p);
}


void Hand::pick_card(Pool &p, int i) {
  cards[i]=p.pick_random();
  
}

void Hand::fill_hand(Pool &p) {
  int i;
  for (i=0; i<Ncards; i++) {
    pick_card(p, i);
  }
  Ncards = 7;
}

ostream &operator<<(ostream &left, Hand &right) {
  for (int i=0; i<right.Ncards; i++) {
    left<<*right.cards[i]<<endl;
  }
  return left;
}
