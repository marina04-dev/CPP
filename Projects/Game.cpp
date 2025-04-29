#include "Game.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

Game::Game() {
    isRunning=true; // when the game is created we set isRunning variable to true
    loadLocations(); // read all .txt files and fill the world
    loadItems();
    loadNPCs();
}

void Game::start() {
    cout<<"Welcome to the Text Adventure Game!\n"; // welcome the player
    player.setCurrentLocation(&locations[0]); // set the player to the first position (e.x. Forest)

    // while the game is active we show the player's location and we wait for 
    // a command (e.x. 'look', 'take', 'talk') and then we act properly
    while(isRunning) {
        showCurrentLocation();
        cout<<"\nEnter command:";
        string command;
        getline(cin,command);
        handleCommand(command);
    }
}

// in those 3 methods we open the file, we read all lines, we separate 
// the name and the description with the ';' and then we add new location to the list
void Game::loadLocations() {
    ifstream file("locations.txt");
    string line;
    while(getline(file,line)) {
        stringstream ss(line);
        string name,description;
        getline(ss,name,';');
        getline(ss,description);
        locations.push_back(Location(name,description));
    }
}

void Game::loadItems() {
    ifstream file("items.txt");
    string line;
    while(getline(file,line)) {
        stringstream ss(line);
        string name;
        getline(ss,name,';');
        items.push_back(Item(name));
    }
}

void Game::loadNPCs() {
    ifstream file("npcs.txt");
    string line;
    while(getline(file,line)) {
        stringstream ss(line);
        string name,dialogue;
        getline(ss,name,';');
        getline(ss,dialogue);
        npcs.push_back(NPC(name,dialogue));
    }
}

void Game::showCurrentLocation() {
    Location* loc=player.getCurrentLocation(); // we take the player's current location
    cout<<"\nYou are at:"<<loc->getName()<<"\n"; // we display the name and the description
    cout<<loc->getDescription()<<"\n";
}

void Game::handleCommand(const string& command) {
    if(command=="look") { // if the player wrote 'look' show again the location
        showCurrentLocation();
    }
    else if(command=="inventory") {  // if the player wrote 'inventory' show the items that the player is holding
        player.showInventory();
    }
    else if(command=="take") { // if the player wrote 'take' it takes the last item from the list and puts it in the player's inventory
        if(!items.empty()) {
            player.addItem(items.back());
            cout<<"You picked up:"<<items.back().getName()<<"\n";
            items.pop_back();
        } else {
            cout<<"There are no items left.\n";
        }
    }
    else if(command=="talk") { // if the player wrote 'talk' we take the last NPC and show it's dialog and then we remove it like it disappears
        if(!npcs.empty()) {
            cout<<npcs.back().talk()<<"\n";
            npcs.pop_back();
        } else {
            cout<<"Nobody is here.\n";
        }
    }
    else if(command=="save") { // save the game if command is 'save'
        saveGame();
    }
    else if(command=="load") { // load the game if command is 'load'
        loadGame();
    }
    else if(command=="quit") { // quit the game if command is 'quit'
        isRunning=false;
    }
    else {
        cout<<"Unknown command.\n";
    }
}

void Game::saveGame() {
    ofstream file("save.txt"); // write to the file the location's name
    file<<player.getCurrentLocation()->getName()<<"\n"; // write also all the player's items
    for(auto& item:player.getInventory()) {
        file<<item.getName()<<"\n";
    }
    cout<<"Game saved!\n";
}

void Game::loadGame() {
    ifstream file("save.txt");
    if(!file.is_open()) { // if there is not a file we stop
        cout<<"No save file found.\n";
        return;
    }
    string locationName;
    getline(file,locationName);

    for(auto& loc:locations) { // read the stored location and move the player there
        if(loc.getName()==locationName) {
            player.setCurrentLocation(&loc);
            break;
        }
    }

    player.clearInventory(); // clear the previous inventory and read all the items that existed in save file
    string itemName;
    while(getline(file,itemName)) {
        player.addItem(Item(itemName));
    }
    cout<<"Game loaded!\n";
}
