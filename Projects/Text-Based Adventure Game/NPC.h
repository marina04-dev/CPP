#ifndef NPC_H
#define NPC_H

#include <string>
using namespace std;

class NPC {
    public:
        NPC(const string& name,const string& dialogue); // constructor
        string talk() const; // what NPC is saying
    private:
        string name; // NPC's name
        string dialogue; // NPC's saying 
};

#endif
