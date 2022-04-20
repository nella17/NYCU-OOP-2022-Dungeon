#include "NPC.hpp"

#include <iostream>
#include <vector>
#include <memory>
#include "helper.hpp"

#include "Player.hpp"

NPC::NPC(std::string _name, std::string _script, ItemsSet _inventory):
        GameCharacter(_name, Object::Type::NPC), script(_script), inventory(std::make_shared<Inventory>(_inventory)) {}

void NPC::print_status(InteractablePtr) {}
void NPC::print_menu() {}
bool NPC::handle_key(int, ObjectPtr) { return false; }

// TODO
bool NPC::trigger_event(ObjectPtr) {
    return false;
}
