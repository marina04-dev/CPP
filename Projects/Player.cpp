#include "Player.h"
#include <iostream>

using namespace std;

Player::Player() { // initialization of player's location 
    currentLocation=nullptr; // set to null at the start
}

void Player::setCurrentLocation(Location* loc) {
    currentLocation=loc; // sets current location to loc given
}

Location* Player::getCurrentLocation() {
    return currentLocation; // gets the current location
}

void Player::addItem(const Item& item) {
    inventory.push_back(item); // add a new item in the list
}

void Player::showInventory() {
    cout<<"Inventory:\n"; // displays the items of the inventory
    if(inventory.empty()) { // if it is empty return empty
        cout<<"(empty)\n";
    }
    for(auto& item:inventory) {
        cout<<"- "<<item.getName()<<"\n"; // display the name of all items
    }
}

vector<Item> Player::getInventory() {
    return inventory; // return a reference to the inventory
}

void Player::clearInventory() {
    inventory.clear(); // clear the inventory
}
