#include "NPC.hpp"

NPC::NPC(string _name, string _script, vector<Item> _commodity):
        GameCharacter(_name, "NPC"), script(_script), commodity(_commodity) {}

// TODO
bool NPC::triggerEvent(const Object_ptr) {
    return true;
}
