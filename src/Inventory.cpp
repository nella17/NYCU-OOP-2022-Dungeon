#include "Inventory.hpp"

Inventory::Inventory(std::string _name, ItemsSet items):
    Interactable(_name, Object::Type::Inventory), ItemsSet(items) {}

void Inventory::print_status(InteractablePtr) {}

void Inventory::print_menu() {}

bool Inventory::handle_key(int, ObjectPtr) {
    return false;
}

bool Inventory::trigger_event(ObjectPtr) {
    return false;
}
