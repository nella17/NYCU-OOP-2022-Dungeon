#include "Equip.hpp"

#include <iostream>
#include "helper.hpp"

Equip::Equip(std::string _name, Type _type, int _health, int _attack, int _defense):
        Item(_name, Object::Type::Equip), type(_type), health(_health), attack(_attack), defense(_defense) {}

std::ostream& Equip::show_info(std::ostream& os) const {
    return os
        << get_name() << "(" << enum_name(type) << "): "
        << "health(" << health << ") / "
        << "attack(" << attack << ") / "
        << "defense(" << defense << ")";
}

int Equip::get_health() const { return health; }
int Equip::get_attack() const { return attack; }
int Equip::get_defense() const { return defense; }
