#ifndef ITEM_H
#define ITEM_H

#include <string>
using namespace std;

class Item {
    public:
        Item(const string& name); // constructor
        string getName() const; // returns item's name
    private:
        string name; // saves the name of the item
};

#endif
