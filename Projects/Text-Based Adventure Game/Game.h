#ifndef GAME_H
#define GAME_H

#include<iostream>
#include<vector>
#include"Player.h"
#include"Location.h"
#include"Item.h"
#include"NPC.h"
using namespace std;

class Game {
    public:
        Game();
        void start();
    private:
        Player player; // the player
        vector<Location> locations; // all game locations
        vector<Item> items; // all items that exist in the game's world
        vector<NPC> npcs; // all characters
        bool isRunning; // checks if the game is still running
        void loadLocations(); // reads the locations from the file
        void loadItems(); // reads the items from the file
        void loadNPCs(); // reads the NPCs from the file
        void showCurrentLocation(); // shows the current player's location
        void handleCommand(const string& command); // handles player's command
        void saveGame(); // saves the game
        void loadGame(); // loads saved game
};

#endif
