#include "Equipment.hpp"

Equipment::Equipment(std::string _name, Type _type, int _health, int _attack, int _defense):
        Item(_name, Object::Type::Equipment), type(_type), health(_health), attack(_attack), defense(_defense) {}

int Equipment::get_health() const { return health; }
int Equipment::get_attack() const { return attack; }
int Equipment::get_defense() const { return defense; }
