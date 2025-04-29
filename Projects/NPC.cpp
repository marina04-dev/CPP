#include"NPC.h"

NPC::NPC(const string& name,const string& dialogue)
:name(name),dialogue(dialogue) {} // constructor

string NPC::talk()const { // NPC's saying
    return name+": "+dialogue; // e.x. "Guard: Halt!"
}
