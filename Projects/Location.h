#ifndef LOCATION_H
#define LOCATION_H

#include <string>
using namespace std;

class Location {
    public:
        Location(const string& name,const string& description); // constructor
        string getName() const; // returns the location's name
        string getDescription() const; // returns the location's description
    private:
        string name; // location's name
        string description; // location's description
};

#endif
