#ifndef PLAYER_H
#define PLAYER_H

#include "Item.h"
#include "Location.h"
#include <vector>
#include <string>

using namespace std;

class Player {
    public:
        Player(); // constructor
        void setCurrentLocation(Location* loc); // defines a new location
        Location* getCurrentLocation(); // takes the current location
        void addItem(const Item& item); // adds an item 
        void showInventory(); // displays all items
        vector<Item> getInventory(); // gets reference of the inventory
        void clearInventory(); // clear the items from the inventory
    private:
        Location* currentLocation; // the current location of the player
        vector<Item> inventory; // the items the player has with him
};

#endif
