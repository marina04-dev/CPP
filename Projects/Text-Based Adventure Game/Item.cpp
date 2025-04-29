#include "Item.h"

using namespace std;

Item::Item(const string& name) {
    this->name=name; // sets the item's name
}

string Item::getName() const {
    return name; // returns the item's name
}
