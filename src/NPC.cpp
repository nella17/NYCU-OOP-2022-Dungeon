#include "NPC.hpp"

#include <iostream>
#include <vector>
#include <memory>
#include "helper.hpp"

#include "Player.hpp"

NPC::NPC(std::string _name, std::string _script, ItemsSet _inventory):
        GameCharacter(_name, Object::Type::NPC),
        script(_script), inventory(std::make_shared<Inventory>(_name, _inventory)) {}

void NPC::print_status(InteractablePtr) {
    std::cout << script << std::endl;
}
void NPC::print_menu() {
    inventory->print_menu();
}
bool NPC::handle_key(int key, ObjectPtr obj) {
    return inventory->handle_key(key, obj);
}

// TODO
bool NPC::trigger_event(ObjectPtr) {
    return false;
}
