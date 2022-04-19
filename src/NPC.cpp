#include "NPC.hpp"

#include <iostream>
#include <vector>
#include <memory>
#include "helper.hpp"

#include "Player.hpp"

NPC::NPC(std::string _name, std::string _script, Items_set _commodity):
        GameCharacter(_name, Object::Type::NPC), script(_script), commodity(_commodity) {}

// TODO
bool NPC::triggerEvent(Object_ptr) {
    return false;
}
