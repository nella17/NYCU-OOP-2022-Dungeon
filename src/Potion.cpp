#include "Potion.hpp"

#include <iostream>

Potion::Potion(std::string _name, int _health, int _attack, int _defense):
        Item(_name, Object::Type::Potion), health(_health), attack(_attack), defense(_defense) {}

std::ostream& Potion::show_info(std::ostream& os) const {
    return os
        << "Protion-" << get_name() << ": "
        << "health(" << health << ") / "
        << "attack(" << attack << ") / "
        << "defense(" << defense << ")";
}

int Potion::get_health() const { return health; }
int Potion::get_attack() const { return attack; }
int Potion::get_defense() const { return defense; }
