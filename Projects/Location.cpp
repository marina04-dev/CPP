#include "Location.h"

using namespace std;

Location::Location(const string& name,const string& description) {
    this->name=name; // location's name constructor set
    this->description=description; // location's description constructor set
}

string Location::getName() const {
    return name; // returns location's name
}

string Location::getDescription() const {
    return description; // returns location's description
}
