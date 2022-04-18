#include "NPC.hpp"

NPC::NPC(string _name, string _script, Items_set _commodity):
        GameCharacter(_name, "NPC"), script(_script), commodity(_commodity) {}

// TODO
bool NPC::triggerEvent(const Object_ptr) {
    return false;
}
