#include "Equipment.hpp"

#include <iostream>
#include "helper.hpp"

Equipment::Equipment(std::string _name, Type _type, int _health, int _attack, int _defense):
        Item(_name, Object::Type::Equipment), type(_type), health(_health), attack(_attack), defense(_defense) {}

std::ostream& Equipment::show_info(std::ostream& os) const {
    return os
        << get_name() << "(" << type << "): "
        << "health(" << health << ") / "
        << "attack(" << attack << ") / "
        << "defense(" << defense << ")";
}

int Equipment::get_health() const { return health; }
int Equipment::get_attack() const { return attack; }
int Equipment::get_defense() const { return defense; }
