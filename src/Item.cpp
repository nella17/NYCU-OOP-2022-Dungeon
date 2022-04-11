#include "Item.hpp"

Item::Item(string _name, int _health, int _attack, int _defense):
        Object(_name, "Item"), health(_health), attack(_attack), defense(_defense) {}

// TODO
bool Item::triggerEvent(const shared_ptr<Object>) {
    return true;
}
