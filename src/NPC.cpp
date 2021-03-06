#include "NPC.hpp"

#include <iostream>
#include <vector>
#include <memory>
#include "helper.hpp"

#include "Player.hpp"

NPC::NPC(std::string _name, std::string _script, ItemsSet _inventory):
        GameCharacter(_name, Object::Type::NPC),
        script(_script), inventory(std::make_shared<Inventory>("NPC Shop", _inventory)) {}

void NPC::print_status(InteractablePtr interact) {
    std::cout << script << std::endl;
    inventory->print_status(interact);
}
void NPC::print_menu() {
    inventory->print_menu();
}
bool NPC::handle_key(int key, ObjectPtr obj) {
    if (key == LEAVE_KEY && obj == nullptr)
        return inventory->empty();

    return inventory->handle_key(key, obj);
}
